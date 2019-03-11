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

string Rules::activityHourToStringDebug(int i)
{
	tm time = Rules::Settings.StartDate;


	int day = i / Rules::Settings.ActivitiesPerDay;

	time.tm_mday += day;
	mktime(&time);
	int activity = i % Rules::Settings.ActivitiesPerDay;

	return "Hour: " + to_string(i) + " Day:" + to_string(day) + " WEEKDAY:" + to_string(getTmWday(time) + 1) + " Activity:" + to_string(activity);
}

string Rules::dayToStringDebug(int i)
{
	tm time = Rules::Settings.StartDate;

	time.tm_mday += i;
	mktime(&time);
	return " Day:" + to_string(i) + " WEEKDAY:" + to_string(getTmWday(time) + 1);

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
	return errorMessage;
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