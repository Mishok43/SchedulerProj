#include "ScheduleObject.h"



ScheduleObject::ScheduleObject(std::string name,std::string description, std::set<std::string> tags)
{
	setName(name);
	setDescription(description);
	this->tags = tags;
	this->killed = false;

}

void ScheduleObject::kill()
{
	killed = true;
}

bool ScheduleObject::isKilled()
{
	return killed;
}


void ScheduleObject::setId(int value)
{
	id = value;
}

int ScheduleObject::getId()
{
	return id;
}


void ScheduleObject::setName(std::string value)
{
	name = value;
}

std::string ScheduleObject::getName()
{
	return killed ? "!!!" : name;
}


void ScheduleObject::setDescription(std::string value)
{
	descripton = value;
}

std::string ScheduleObject::getDescription()
{
	return descripton;
}

Rules& ScheduleObject::getRules()
{
	return rules;
}


cli::array<System::String^>^ ScheduleObject::getParamRow()
{
	cli::array<System::String^>^ a = gcnew cli::array<System::String^>(getParamNum());
	for (int i = 0; i < getParamNum(); i++)
		//a[i] = StdToSys(getParam(i));
		a[i] = gcnew System::String(getParam(i).c_str());

	return a;
}

set<string> ScheduleObject::getTags()
{
	return tags;
}

std::string ScheduleObject::getTagsAsString()
{
	return setToString(tags);
}


void ScheduleObject::setTagsFromString(string value)
{
	tags = stringToSet(value);
}


void ScheduleObject::addTag(string value)
{
	tags.insert(value);
}

void ScheduleObject::removeTag(string value)
{
	tags.erase(value);
}
string setToString(set<string> list)
{

	std::string s;

	int i = 0;
	for (auto const& e : list)
	{
		if (i > 0)
			s += ", ";
		s += e;
		i++;

	}
	return s;
}
set<string> stringToSet(string str)
{

	std::set<std::string> temp;
	int i = 0;
	for (int j = 0; j < str.size(); j++)
		if (str[j] == ',')
		{
			temp.insert(str.substr(i, j - i));
			i = j + 2;
		}
	if (!str.empty())
		temp.insert(str.substr(i, str.size() - i));


	return temp;
}
std::ostream& operator<<(std::ostream& os, ScheduleObject& obj)
{
	obj.ostreamF(os);
	return os;
}

std::istream& operator>>(std::istream& is,  ScheduleObject& obj)
{
	obj.istreamF(is);
	return is;
}

std::vector<Classroom*> Classroom::ExcelToClassrooms(const char * path)
{
	std::vector<Classroom*> v;
	ExcelFormat::BasicExcel xls(path);
	ExcelFormat::BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	int i = 1;
	while (!sheet->Cell(i, 0)->GetValue().empty())
	{
		string name = sheet->Cell(i, 0)->GetValue();
		int capacity = std::stoi(sheet->Cell(i, 1)->GetValue());
		string description = sheet->Cell(i, 2)->GetValue();
		string tags = sheet->Cell(i, 3)->GetValue();

		Classroom* obj = new Classroom(name,description, {}, capacity);
		obj->setTagsFromString(tags);
		v.push_back(obj);
		++i;
	}
		
	return v;
}

void Classroom::ClassroomsToExcel(vector<Classroom*> v, const char * path)
{
	ExcelFormat::BasicExcel xls;
	xls.New(1);
	ExcelFormat::BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	sheet->Cell(0, 0)->SetValue("Идентификатор");
	sheet->Cell(0, 1)->SetValue("Вместимость");
	sheet->Cell(0, 2)->SetValue("Комментарии");
	sheet->Cell(0, 3)->SetValue("Теги");

	sheet->SetColWidth(0, 15*300);
	sheet->SetColWidth(1, 13*300);
	sheet->SetColWidth(2, 30*300);
	sheet->SetColWidth(3, 35*300);

	for (int i = 0; i < v.size(); i++)
	{
		sheet->Cell(i + 1, 0)->SetValue(v[i]->getName());
		sheet->Cell(i + 1, 1)->SetInteger(v[i]->getCapacity());
		sheet->Cell(i + 1, 2)->SetValue(v[i]->getDescription());
		sheet->Cell(i + 1, 3)->SetValue(v[i]->getTagsAsString());
	}

	xls.SaveAs(path);
}


Classroom::Classroom() : ScheduleObject("?","?", {})
{
	this->capacity = 0;
}

Classroom::Classroom(std::string name,std::string description, std::set<std::string> tags, int capacity) : ScheduleObject(name,description, tags)
{
	this->capacity = capacity;
}

int Classroom::getCapacity()
{
	return capacity;
}

void Classroom::setCapacity(int value)
{
	capacity = value;
}


std::string Classroom::getParam(int i)
{
	std::string s = "";
	switch (i)
	{
	case 0: s = name; break;
	case 1: s = std::to_string(capacity); break;
	case 2: s = descripton;  break;
	case 3: s = rules.isEmpty() ? "" : "+"; break;
	case 4: s = getTagsAsString(); break;
	}
	return s;
}
int Classroom::getParamNum()
{
	return 5;
}

void Classroom::ostreamF(std::ostream& os)
{

	string t = getTagsAsString();
	os << name << endl;
	os << capacity << endl;
	os << descripton << endl;
	os << t << endl;
	os << rules;

	

}

void Classroom::istreamF(std::istream& is)
{
	string temp;

	getline(is,name);
	getline(is, temp);
	capacity = atoi(temp.c_str());
	getline(is, descripton);
	getline(is, temp);
	setTagsFromString(temp);
	is >> rules;
}

std::vector<Teacher*> Teacher::ExcelToTeachers(const char * path)
{
	std::vector<Teacher*> v;
	ExcelFormat::BasicExcel xls(path);
	ExcelFormat::BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	int i = 1;
	while (!sheet->Cell(i, 0)->GetValue().empty())
	{
		string name = sheet->Cell(i, 0)->GetValue();
		string description = sheet->Cell(i, 1)->GetValue();
		string tags = sheet->Cell(i, 2)->GetValue();

		Teacher* obj = new Teacher(name, description, {});
		obj->setTagsFromString(tags);
		v.push_back(obj);
		++i;
	}
	return v;
}

void Teacher::TeachersToExcel(vector<Teacher*> v, const char * path)
{
	ExcelFormat::BasicExcel xls;
	xls.New(1);
	ExcelFormat::BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	sheet->Cell(0, 0)->SetValue("Фамилия Имя Отчество");
	sheet->Cell(0, 1)->SetValue("Комментарии");
	sheet->Cell(0, 2)->SetValue("Теги");

	sheet->SetColWidth(0, 35 * 300);
	sheet->SetColWidth(1, 30 * 300);
	sheet->SetColWidth(2, 35 * 300);

	for (int i = 0; i < v.size(); i++)
	{
		sheet->Cell(i + 1, 0)->SetValue(v[i]->getName());
		sheet->Cell(i + 1, 1)->SetValue(v[i]->getDescription());
		sheet->Cell(i + 1, 2)->SetValue(v[i]->getTagsAsString());
	}

	xls.SaveAs(path);
}

Teacher::Teacher() : ScheduleObject("?", "?", {})
{
}

Teacher::Teacher(std::string name, std::string description, std::set<std::string> tags) : ScheduleObject(name, description, tags)
{
}

string Teacher::getShortName()
{
	string s;

	int z = name.find_first_of(' ');

	s = name.substr(0, z) + " ";

	while (z < name.length() - 2)
	{
		if (name[z] == ' ')
		{
			s += name[z + 1];
			s += '.';
		}
		else if (name[z] == '.')
		{
			if (name[z + 1] != ' ')
			{
				s += name[z + 1];
				s += '.';
			}
				
		}

		z++;
	}

	return s;



}

void Teacher::ostreamF(std::ostream & os)
{
	string t = getTagsAsString();
	os << name << endl;
	os << descripton << endl;
	os << t << endl;
	os << rules;
}

void Teacher::istreamF(std::istream & is)
{
	string temp;

	getline(is, name);
	getline(is, descripton);
	getline(is, temp);
	setTagsFromString(temp);
	is >> rules;
}

std::string Teacher::getParam(int i)
{
	std::string s = "";
	switch (i)
	{
	case 0: s = name; break;
	case 1: s = descripton;  break;
	case 2: s = rules.isEmpty() ? "" : "+"; break;
	case 3: s = getTagsAsString(); break;
	}
	return s;
}

int Teacher::getParamNum()
{
	return 4;
}


std::vector<Group*> Group::ExcelToGroups(const char * path)
{
	std::vector<Group*> v;
	ExcelFormat::BasicExcel xls(path);
	ExcelFormat::BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	int i = 1;
	while (!sheet->Cell(i, 0)->GetValue().empty())
	{
		string name = sheet->Cell(i, 0)->GetValue();
		int size = std::stoi(sheet->Cell(i, 1)->GetValue());
		string description = sheet->Cell(i, 2)->GetValue();
		string tags = sheet->Cell(i, 3)->GetValue();

		Group* obj = new Group(name, description, {}, size);
		obj->setTagsFromString(tags);
		v.push_back(obj);
		++i;
	}

	return v;
}

void Group::GroupsToExcel(vector<Group*> v, const char * path)
{
	ExcelFormat::BasicExcel xls;
	xls.New(1);
	ExcelFormat::BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	sheet->Cell(0, 0)->SetValue("Идентификатор");
	sheet->Cell(0, 1)->SetValue("Размер");
	sheet->Cell(0, 2)->SetValue("Комментарии");
	sheet->Cell(0, 3)->SetValue("Теги");

	sheet->SetColWidth(0, 15 * 300);
	sheet->SetColWidth(1, 13 * 300);
	sheet->SetColWidth(2, 30 * 300);
	sheet->SetColWidth(3, 35 * 300);

	for (int i = 0; i < v.size(); i++)
	{
		sheet->Cell(i + 1, 0)->SetValue(v[i]->getName());
		sheet->Cell(i + 1, 1)->SetInteger(v[i]->getSize());
		sheet->Cell(i + 1, 2)->SetValue(v[i]->getDescription());
		sheet->Cell(i + 1, 3)->SetValue(v[i]->getTagsAsString());
	}

	xls.SaveAs(path);
}


Group::Group() : ScheduleObject("?", "?", {})
{
	this->size = 0;
}

Group::Group(std::string name, std::string description, std::set<std::string> tags, int size) : ScheduleObject(name, description, tags)
{
	this->size = size;
}

int Group::getSize()
{
	return size;
}

void Group::setSize(int value)
{
	size = value;
}


std::string Group::getParam(int i)
{
	std::string s = "";
	switch (i)
	{
	case 0: s = name; break;
	case 1: s = std::to_string(size); break;
	case 2: s = descripton;  break;
	case 3: s = rules.isEmpty() ? "" : "+"; break;
	case 4: s = getTagsAsString(); break;
	}
	return s;
}
int Group::getParamNum()
{
	return 5;
}

void Group::ostreamF(std::ostream& os)
{

	string t = getTagsAsString();
	os << name << endl;
	os << size << endl;
	os << descripton << endl;
	os << t << endl;
	os << rules;



}

void Group::istreamF(std::istream& is)
{
	string temp;

	getline(is, name);
	getline(is, temp);
	size = atoi(temp.c_str());
	getline(is, descripton);
	getline(is, temp);
	setTagsFromString(temp);
	is >> rules;
}





std::vector<Activity*> Activity::ExcelToActivities(const char * path)
{
	std::vector<Activity*> v;
	ExcelFormat::BasicExcel xls(path);
	ExcelFormat::BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	int i = 1;
	while (!sheet->Cell(i, 0)->GetValue().empty())
	{
		string name = sheet->Cell(i, 0)->GetValue();
		string teacherName = sheet->Cell(i, 1)->GetValue();
		string groupNames = sheet->Cell(i, 2)->GetValue();
		int hours = std::stoi(sheet->Cell(i, 3)->GetValue());
		string description = sheet->Cell(i, 4)->GetValue();
		string tags = sheet->Cell(i, 5)->GetValue();
		
		Activity* obj = new Activity(name, description, stringToSet(tags),teacherName,stringToSet(groupNames), hours);
		
		v.push_back(obj);
		++i;
	}

	return v;
}

void Activity::ActivitiesToExcel(vector<Activity*> v, const char * path)
{
	ExcelFormat::BasicExcel xls;
	xls.New(1);
	ExcelFormat::BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	sheet->Cell(0, 0)->SetValue("Название");
	sheet->Cell(0, 1)->SetValue("Преподаватель");
	sheet->Cell(0, 2)->SetValue("Группы");
	sheet->Cell(0, 3)->SetValue("Часы");
	sheet->Cell(0, 4)->SetValue("Комментарии");
	sheet->Cell(0, 5)->SetValue("Теги");

	sheet->SetColWidth(0, 15 * 300);
	sheet->SetColWidth(1, 13 * 300);
	sheet->SetColWidth(2, 30 * 300);
	sheet->SetColWidth(3, 35 * 300);
	sheet->SetColWidth(4, 30 * 300);
	sheet->SetColWidth(5, 35 * 300);

	for (int i = 0; i < v.size(); i++)
	{
		sheet->Cell(i + 1, 0)->SetValue(v[i]->getName());
		sheet->Cell(i + 1, 1)->SetValue(v[i]->getTeacherName());
		sheet->Cell(i + 1, 2)->SetValue(v[i]->getGroupsAsString());
		sheet->Cell(i + 1, 3)->SetInteger(v[i]->getHours());
		sheet->Cell(i + 1, 4)->SetValue(v[i]->getDescription());
		sheet->Cell(i + 1, 5)->SetValue(v[i]->getTagsAsString());
	}

	xls.SaveAs(path);
}


Activity::Activity() : ScheduleObject("?", "?", {})
{
	this->hours = 0;
}

Activity::Activity(std::string name, std::string description, std::set<std::string> tags, string teacherName,set<string> groupNames,int hours) : ScheduleObject(name, description, tags)
{
	this->hours = hours;
	setTeacher(teacherName);
	setGroups(groupNames);
}

int Activity::getHours()
{
	return hours;
}

void Activity::setHours(int value)
{
	hours = value;
}

void Activity::setTeacher(string teacherName)
{
	this->teacher = Activity::GlobalTeachers.getByName(teacherName);

}

Teacher * Activity::getTeacher()
{
	return teacher;
}

string Activity::getTeacherName()
{
	return teacher ? teacher->getName() : "???";
}

string Activity::getTeacherShortName()
{
	return teacher ? teacher->getShortName() : "???";
}

void Activity::setGroups(set<string> groupNames)
{
	this->groups.clear();
	for (auto s : groupNames)
	{
		Group* p = Activity::GlobalGroups.getByName(s);
		this->groups.insert(p);

	}
}

set<Group*>& Activity::getGroups()
{
	return groups;
}

string Activity::getGroupsAsString()
{
	set<string> list;
	for (auto g : groups)
		if (g)
			list.insert(g->getName());
		else
			list.insert("???");
	return setToString(list);
}


std::string Activity::getParam(int i)
{
	std::string s = "";
	switch (i)
	{
	case 0: s = name; break;
	case 1: s = getTeacherShortName(); break;
	case 2: s = getGroupsAsString();  break;
	case 3: s = to_string(hours); break;
	case 4: s = descripton;  break;
	case 5: s = rules.isEmpty() ? "" : "+"; break;
	case 6: s = getTagsAsString(); break;
	}
	return s;
}
int Activity::getParamNum()
{
	return 7;
}

void Activity::ostreamF(std::ostream& os)
{

	os << name << endl;
	os << getTeacherName() << endl;
	os << getGroupsAsString() << endl;
	os << hours << endl;
	os << descripton << endl;
	os << getTagsAsString() << endl;
	os << rules;



}

void Activity::istreamF(std::istream& is)
{
	string temp;

	getline(is, name);
	getline(is, temp);
	teacher = Activity::GlobalTeachers.getByName(temp);
	getline(is, temp);
	for (auto s : stringToSet(temp))
	{
		Group* p = Activity::GlobalGroups.getByName(s);
		if (p != nullptr)
			groups.insert(p);
	}
	getline(is, temp);
	hours = atoi(temp.c_str());
	getline(is, descripton);
	getline(is, temp);
	setTagsFromString(temp);
	is >> rules;
}

