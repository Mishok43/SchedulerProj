#include "Rules.h"






int getTmWday(tm& time) {
	switch (time.tm_wday)
	{
	case 0: return 6; break;
	default: return time.tm_wday - 1; break;
	}
	return 0;


}


ostream& operator<<(ostream& os, RulesSettings& settings)
{

	os << settings.StartDate.tm_year << endl;
	os << settings.StartDate.tm_mon << endl;
	os << settings.StartDate.tm_mday << endl;
	os << settings.Days << endl;
	os << settings.ActivitiesPerDay << endl;

	for (int i = 0; i < 20; i++)
	{
		os << settings.ActivityStartTime[i] << endl;
		os << settings.ActivityEndTime[i] << endl;
	}

	return os;
}

istream& operator>>(istream& is, RulesSettings& settings)
{

	string temp;
	getline(is, temp);
	settings.StartDate.tm_year = atoi(temp.c_str());
	getline(is, temp);
	settings.StartDate.tm_mon = atoi(temp.c_str());
	getline(is, temp);
	settings.StartDate.tm_mday = atoi(temp.c_str());
	getline(is, temp);
	settings.Days = atoi(temp.c_str());
	getline(is, temp);
	settings.ActivitiesPerDay = atoi(temp.c_str());


	for (int i = 0; i < 20; i++)
	{
		getline(is, temp);
		settings.ActivityStartTime[i] = (atoi(temp.c_str()));
		getline(is, temp);
		settings.ActivityEndTime[i] = (atoi(temp.c_str()));
	}


	return is;
}

RulesSettings Rules::Settings;


void RuleData::init()
{
	errorMessage = "";
	m = new bool*[Rules::Settings.Days];
	for (int i = 0; i < Rules::Settings.Days; i++)
	{
		m[i] = new bool[Rules::Settings.ActivitiesPerDay];
		for (int j = 0; j < Rules::Settings.ActivitiesPerDay; j++)
			m[i][j] = true;
	}

	obj = new bool*[4];
	for (int i = 0; i < 4; i++)
	{
		obj[i] = new bool[Rules::Settings.nameMapSize[i]];
		for (int j = 0; j < Rules::Settings.nameMapSize[i]; j++)
			obj[i][j] = true;
	}

	maxPerWeek = Rules::Settings.ActivitiesPerDay * 7;

	type = FULLT;
}

RuleData::RuleData()
{
	init();
}


void RuleData::parse(string& errM, string& s, signtype& st, functype& ft, vector<string>& arg)
{
	st = EQUAL;


	int i = 0;
	while (s[i] != '(')
		i++;

	string nm = s.substr(0, i);
	ft = UNKNOWN;
	if (nm == "Не")
		ft = NOT;
	if (nm == "И")
		ft = AND;
	if (nm == "Или")
		ft = OR;
	if (nm == "Пара")
		ft = HOUR;
	if (nm == "Время")
		ft = TIME;
	if (nm == "ДеньНед")
		ft = WEEKDAY;
	if (nm == "Месяц")
		ft = MONTH;
	if (nm == "Дата")
		ft = DATE;
	if (nm == "Группа")
		ft = GROUP;
	if (nm == "Препод")
		ft = TEACHER;
	if (nm == "Дисцип")
		ft = ACTIVITY;
	if (nm == "Ауд")
		ft = CLASSROOM;
	if (nm == "МаксВНеделю")
		ft = HPERWEEK;

	if (ft == UNKNOWN)
	{
		errM = "Неизвестная функция: " + nm;
		return;

	}

	i++;

	if (s[i] == '=')
		i += 1;
	else
	{
		if (s[i] == '<')
		{
			i += 1;
			st = LESS;
			if (s[i] == '=')
			{
				i += 1;
				st = ELESS;
			}
		}
		else if (s[i] == '>')
		{
			i += 1;
			st = GREATER;
			if (s[i] == '=')
			{
				i += 1;
				st = EGREATER;
			}

		}
	}

	int bracketnum = 1;
	string news = "";
	while (bracketnum > 0)
	{


		if (s[i] == ')') bracketnum -= 1;
		if (s[i] == '(') bracketnum += 1;

		if (s[i] == ',' && bracketnum == 1
			|| s[i] == ')' && bracketnum == 0)
		{
			arg.push_back(news);
			news = "";
		}
		else
		{
			news += s[i];
		}



		i++;
	}

}

RuleData::RuleData(string s) : RuleData()
{
	errorMessage = "";
	signtype st = EQUAL;
	functype ft = UNKNOWN;
	vector<string> arg = vector<string>();
	parse(errorMessage, s, st, ft, arg);
	
	if (!errorMessage.empty())
		return;

	RuleData rd;
	int hour, min, k, from, to, time;
	switch (ft)
	{
	case NOT: //Не
		if (!arg.size() == 1)
		{
			errorMessage = "Неверное число аргументов функции: " + s;
			return;
		}

		rd = RuleData(arg[0]);
		rd.not();
		and (rd);
		type = rd.type;

		break;
	case AND: //И

		if (arg.size() < 2)
		{
			errorMessage = "Неверное число аргументов функции: " + s;
			return;
		}

		for (auto a : arg)
		{
			rd = RuleData(a);
			and (rd);
			type = rd.type;
		}

		break;
	case OR: //Или

		if (arg.size() < 2)
		{
			errorMessage = "Неверное число аргументов функции: " + s;
			return;
		}

		k = 0;
		for (auto a : arg)
		{
			rd = RuleData(a);
			if (k == 0)
				and (rd);
			else
				or (rd);
			type = rd.type;
			k++;
		}
		break;
	case HOUR: //Пара
		type = TIMET;
		try {
			k = stoi(arg[0]) - 1;
			}
		catch (...)
		{
			errorMessage = "Аргумент неверного формата: " + s;
			return;
		}



		switch (st)
		{
		case LESS:
			from = 0; to = k - 1;
			break;
		case ELESS:
			from = 0; to = k;
			break;
		case EQUAL:
			from = k; to = k;
			break;
		case GREATER:
			from = k + 1; to = Rules::Settings.ActivitiesPerDay - 1;
			break;
		case EGREATER:
			from = k; to = Rules::Settings.ActivitiesPerDay - 1;
			break;
		}

		if (from < 0 || to > Rules::Settings.ActivitiesPerDay)
		{
			errorMessage = "Значение вне границ количества пар: " + s;
			return;
		}


		for (int i = 0; i < Rules::Settings.ActivitiesPerDay; i++)
			if (i < from || i > to)
				for (int j = 0; j < Rules::Settings.Days; j++)
					m[j][i] = false;
		break;
	case TIME: //Время
		type = TIMET;
		k = arg[0].find(":");
		hour = stoi(arg[0].substr(0, k));;
		min = stoi(arg[0].substr(k + 1, arg[0].length() - k - 1));
		time = hour * 60 + min;

		switch (st)
		{
		case LESS:
			from = 0; to = time - 1;
			break;
		case ELESS:
			from = 0; to = time;
			break;
		case EQUAL:
			from = time; to = time;
			break;
		case GREATER:
			from = time + 1; to = 24 * 60;
			break;
		case EGREATER:
			from = time; to = 24 * 60;
			break;
		}

		for (int i = 0; i < Rules::Settings.ActivitiesPerDay; i++)
			if (!(Rules::Settings.ActivityStartTime[i] >= from &&
				Rules::Settings.ActivityEndTime[i] <= to))
				for (int j = 0; j < Rules::Settings.Days; j++)
					m[j][i] = false;

		break;
	case WEEKDAY: //ДеньНед

		type = TIMET;

		if (arg[0] == "Понедельник")
			k = 0;
		else if (arg[0] == "Вторник")
			k = 1;
		else if (arg[0] == "Среда")
			k = 2;
		else if (arg[0] == "Четверг")
			k = 3;
		else if (arg[0] == "Пятница")
			k = 4;
		else if (arg[0] == "Суббота")
			k = 5;
		else if (arg[0] == "Воскресенье")
			k = 6;
		else  {
			errorMessage = "Неизестный тип дня недели: " + s;
			return;
		}

		switch (st)
		{
		case LESS:
			from = 0; to = k - 1;
			break;
		case ELESS:
			from = 0; to = k;
			break;
		case EQUAL:
			from = k; to = k;
			break;
		case GREATER:
			from = k + 1; to = 6;
			break;
		case EGREATER:
			from = k; to = 6;
			break;
		}

		for (int i = 0; i < Rules::Settings.Days; i++)
			if (Rules::dayToWeekday(i) < from || Rules::dayToWeekday(i) > to)
				for (int j = 0; j < Rules::Settings.ActivitiesPerDay; j++)
					m[i][j] = false;

		break;
	case MONTH: //Месяц

		type = TIMET;

		if (arg[0] == "Январь")
			k = 0;
		else if (arg[0] == "Февраль")
			k = 1;
		else if (arg[0] == "Март")
			k = 2;
		else if (arg[0] == "Апрель")
			k = 3;
		else if (arg[0] == "Май")
			k = 4;
		else if (arg[0] == "Июнь")
			k = 5;
		else if (arg[0] == "Июль")
			k = 6;
		else if (arg[0] == "Август")
			k = 7;
		else if (arg[0] == "Сентябрь")
			k = 8;
		else if (arg[0] == "Октябрь")
			k = 9;
		else if (arg[0] == "Ноябрь")
			k = 10;
		else if (arg[0] == "Декабрь")
			k = 11;
		else
		{
			errorMessage = "Неизестный тип месяца: " + s;
			return;
		}

		switch (st)
		{
		case LESS:
			from = 0; to = k - 1;
			break;
		case ELESS:
			from = 0; to = k;
			break;
		case EQUAL:
			from = k; to = k;
			break;
		case GREATER:
			from = k + 1; to = 11;
			break;
		case EGREATER:
			from = k; to = 11;
			break;
		}

		for (int i = 0; i < Rules::Settings.Days; i++)
			if (Rules::dayToMonth(i) < from || Rules::dayToMonth(i) > to)
				for (int j = 0; j < Rules::Settings.ActivitiesPerDay; j++)
					m[i][j] = false;


		break;
	case DATE: //Дата

		type = TIMET;

		if (arg[0].length()!=8)
		{
			errorMessage = "Дата неверного формата: " + s;
			return;
		}

		tm date = Rules::Settings.StartDate;
		try {
			date.tm_year = 2000 + stoi(arg[0].substr(6, 2)) - 1900;
			date.tm_mon = stoi(arg[0].substr(3, 2)) - 1;
			date.tm_mday = stoi(arg[0].substr(0, 2));
		}
		catch (...)
		{
			errorMessage = "Дата неверного формата: " + s;
			return;
		}

		
		

		k = Rules::dateToDay(date);


		switch (st)
		{
		case LESS:
			from = 0; to = k - 1;
			break;
		case ELESS:
			from = 0; to = k;
			break;
		case EQUAL:
			from = k; to = k;
			break;
		case GREATER:
			from = k + 1; to = 99999;
			break;
		case EGREATER:
			from = k; to = 99999;
			break;
		}

		for (int i = 0; i < Rules::Settings.Days; i++)
			if (i < from || i > to)
				for (int j = 0; j < Rules::Settings.ActivitiesPerDay; j++)
					m[i][j] = false;
		break;
	case GROUP: //Группа

		type = GROUPT;

		k = 0;
		for (int i = 0; i < Rules::Settings.nameMapSize[k]; i++)
			obj[k][i] = false;

		if (Rules::Settings.nameMap[k].find(arg[0]) == Rules::Settings.nameMap[k].end())
		{
			errorMessage = "Неизвестный идентификатор: " + s;
			return;
		}

		for (auto e : Rules::Settings.nameMap[k][arg[0]])
			obj[k][e] = true;

		break;
	case TEACHER: //Препод

		type = TEACHERT;

		k = 1;
		for (int i = 0; i < Rules::Settings.nameMapSize[k]; i++)
			obj[k][i] = false;

		if (Rules::Settings.nameMap[k].find(arg[0]) == Rules::Settings.nameMap[k].end())
		{
			errorMessage = "Неизвестный идентификатор: " + s;
			return;
		}


		for (auto e : Rules::Settings.nameMap[k][arg[0]])
			obj[k][e] = true;

		break;
	case ACTIVITY: //Дисцип

		type = ACTIVITYT;

		k = 2;
		for (int i = 0; i < Rules::Settings.nameMapSize[k]; i++)
			obj[k][i] = false;

		if (Rules::Settings.nameMap[k].find(arg[0]) == Rules::Settings.nameMap[k].end())
		{
			errorMessage = "Неизвестный идентификатор: " + s;
			return;
		}

		for (auto e : Rules::Settings.nameMap[k][arg[0]])
			obj[k][e] = true;

		break;
	case CLASSROOM: //Аудит

		type = CLASSROOMT;

		k = 3;
		for (int i = 0; i < Rules::Settings.nameMapSize[k]; i++)
			obj[k][i] = false;

		if (Rules::Settings.nameMap[k].find(arg[0]) == Rules::Settings.nameMap[k].end())
		{
			errorMessage = "Неизвестный идентификатор: " + s;
			return;
		}

		for (auto e : Rules::Settings.nameMap[k][arg[0]])
			obj[k][e] = true;


		break;
	case HPERWEEK: //МаксВНеделю

		type = HWEEKT;

		

		try {
			maxPerWeek = stoi(arg[0]);
		}
		catch (...)
		{
			errorMessage = "Аргумент неверного формата: " + s;
			return;
		}

		if (maxPerWeek<=0)
			errorMessage = "Аргумент вне допустимого диапазона: " + s;


		break;
	}


}


RuleData::~RuleData()
{
	//for (int i = 0; i < Rules::Settings.Days; i++)
	//	delete[] m[i];
	//delete[] m;
}

void RuleData:: and (RuleData& other)
{
	if (!errorMessage.empty())
		return;
	errorMessage = other.getErrorMessage();
	if (!errorMessage.empty())
		return;


	if (other.type == TIMET || other.type == FULLT)
		for (int i = 0; i < Rules::Settings.Days; i++)
			for (int j = 0; j < Rules::Settings.ActivitiesPerDay; j++)
				m[i][j] = m[i][j] && other.m[i][j];

	for (int i = 0; i < 4; i++)
		if (other.type == i + 2 || other.type == FULLT)
			for (int j = 0; j < Rules::Settings.nameMapSize[i]; j++)
				obj[i][j] = obj[i][j] && other.obj[i][j];

	if (other.type == HWEEKT || other.type == FULLT)
		if (other.maxPerWeek < maxPerWeek)
			maxPerWeek = other.maxPerWeek;
}
void RuleData:: or (RuleData& other)
{
	if (!errorMessage.empty())
		return;
	errorMessage = other.getErrorMessage();
	if (!errorMessage.empty())
		return;

	if (other.type == TIMET || other.type == FULLT)
		for (int i = 0; i < Rules::Settings.Days; i++)
			for (int j = 0; j < Rules::Settings.ActivitiesPerDay; j++)
				m[i][j] = m[i][j] || other.m[i][j];

	for (int i = 0; i < 4; i++)
		if (other.type == i + 2 || other.type == FULLT)
			for (int j = 0; j < Rules::Settings.nameMapSize[i]; j++)
				obj[i][j] = obj[i][j] || other.obj[i][j];

	if (other.maxPerWeek > maxPerWeek)
		maxPerWeek = other.maxPerWeek;
}
void RuleData::not()
{
	for (int i = 0; i < Rules::Settings.Days; i++)
		for (int j = 0; j < Rules::Settings.ActivitiesPerDay; j++)
			m[i][j] = !m[i][j];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < Rules::Settings.nameMapSize[i]; j++)
			obj[i][j] = !obj[i][j];
}


bool RuleData::hasFullyEmptyRegion()
{
	bool hasTrue = false;
	for (int i = 0; i < Rules::Settings.Days; i++)
		for (int j = 0; j < Rules::Settings.ActivitiesPerDay; j++)
			if (m[i][j])
				hasTrue = true;

	

	for (int i = 0; i < 4; i++)
	{
		if (!hasTrue)
			return !hasTrue;

		hasTrue = false;

		for (int j = 0; j < Rules::Settings.nameMapSize[i]; j++)
			if (obj[i][j])
				hasTrue = true;
	}
		

	return !hasTrue;
}

bool RuleData::canDayDaytime(int day, int daytime)
{
	return m[day][daytime];
}

bool RuleData::canObj(objtype type, int id)
{
	return obj[type][id];
}
int RuleData::getMaxPerWeek()
{
	return maxPerWeek;
}


string RuleData::getErrorMessage()
{
	return errorMessage;
}

string Rules::activityHourToStringDebug(int i)
{
	tm time = Rules::Settings.StartDate;


	int day = i / Rules::Settings.ActivitiesPerDay;

	time.tm_mday += day;
	mktime(&time);
	int activity = i % Rules::Settings.ActivitiesPerDay;

	return "Hour: " + to_string(i) + " WEEKDAY:" + to_string(getTmWday(time) + 1) + " Activity:" + to_string(activity);
}

string Rules::dayToStringDebug(int i)
{
	tm time = Rules::Settings.StartDate;

	time.tm_mday += i;
	mktime(&time);
	return " Day:" + to_string(i) + "\nDate:" + to_string(time.tm_mday) + "/" + to_string(time.tm_mon + 1) + "\nweekDay:" + to_string(getTmWday(time) + 1);

}

int Rules::dayToWeekday(int i)
{
	tm time = Rules::Settings.StartDate;

	time.tm_mday += i;
	mktime(&time);
	return getTmWday(time);
}

int Rules::dayToMonth(int i)
{
	tm time = Rules::Settings.StartDate;

	time.tm_mday += i;
	mktime(&time);
	return time.tm_mon;
}

tm Rules::dayToDate(int i)
{
	tm time = Rules::Settings.StartDate;

	time.tm_mday += i;
	mktime(&time);
	return time;
}
int Rules::dateToDay(tm date)
{
	tm time = Rules::Settings.StartDate;

	time_t x = mktime(&time);
	time_t y = mktime(&date);
	if (x != (time_t)(-1) && y != (time_t)(-1))
		return std::difftime(y, x) / (60 * 60 * 24);
	return 0;
}


Rules::Rules()
{

}


void Rules::setText(vector<string> text)
{
	this->text.clear();

	for (int i = 0; i < text.size(); i++)
		if (!text[i].empty())
			this->text.push_back(text[i]);

}

vector<string>& Rules::getText()
{
	return text;
}


string Rules::getErrorMessage()
{

	if (data.hasFullyEmptyRegion())
		return "В ограничениях присутствует пустое множество";

	return data.getErrorMessage();
}

void Rules::update()
{
	data.init();
	for (int i = 0; i < text.size(); i++)
	{
		data. and (RuleData(text[i]));
	}
}

bool Rules::isEmpty()
{
	return text.empty();
}

RuleData& Rules::getData()
{
	return data;
}

ostream& operator<<(ostream& os, Rules& rules)
{

	vector<string> list = rules.getText();

	os << list.size() << endl;
	for (int i = 0; i < list.size(); i++)
		os << list[i] << endl;
	return os;
}

istream& operator>>(istream& is, Rules& rules)
{
	string temp;
	vector<string> list;
	int n;
	getline(is, temp);
	n = atoi(temp.c_str());
	for (int i = 0; i < n; i++)
	{
		getline(is, temp);
		list.push_back(temp);
	}

	rules.setText(list);
	return is;
}


TagRules::TagRules()
{

}

void TagRules::setText(vector<string> text)
{
	m.clear();

	for (int i = 0; i < text.size(); i++)
	{
		if (text[i].empty())
			continue;

		int z = text[i].find_first_of(':');

		if (z == string::npos)
			continue;

		z++;

		string key = text[i].substr(0, z - 1);
		string val = text[i].substr(z + 1, text[i].length() - z - 1);

		if (m.find(key) == m.end())
			m.insert(std::pair<string, Rules>(key, Rules()));

		m[key].getText().push_back(val);
	}
}

vector<string> TagRules::getText()
{
	vector<string> v;

	for (map<string, Rules>::iterator it = m.begin(); it != m.end(); ++it)
	{
		string k = it->first;

		if (k.empty())
			continue;
		vector<string> txt = it->second.getText();
		for (int i = 0; i < txt.size(); i++)
			v.push_back(k + ": " + txt[i]);
	}


	return v;
}

void TagRules::update()
{
	for (map<string, Rules>::iterator it = m.begin(); it != m.end(); ++it)
	{
		it->second.update();
	}
}

map<string, Rules>& TagRules::getMap()
{
	return m;
}

vector<pair<string, string>> TagRules::getErrors(string pre)
{
	vector<pair<string, string>> v;


	for (map<string, Rules>::iterator it = m.begin(); it != m.end(); ++it)
	{
		if (!it->second.getErrorMessage().empty())
		{
			v.push_back(pair<string, string>(pre+": "+it->first,it->second.getErrorMessage()));
		}
	}

	return v;
}

ostream& operator<<(ostream& os, TagRules& tagRules)
{

	vector<string> list = tagRules.getText();

	os << list.size() << endl;
	for (int i = 0; i < list.size(); i++)
		os << list[i] << endl;
	return os;
}

istream& operator>>(istream& is, TagRules& tagRules)
{
	string temp;
	vector<string> list;
	int n;
	getline(is, temp);
	n = atoi(temp.c_str());
	for (int i = 0; i < n; i++)
	{
		getline(is, temp);
		list.push_back(temp);
	}

	tagRules.setText(list);
	return is;
}