#include "ScheduleObject.h"



ScheduleObject::ScheduleObject(std::string name,std::string description, std::set<std::string> tags)
{
	setName(name);
	setDescription(description);
	this->tags = tags;

}




void ScheduleObject::setName(std::string value)
{
	name = value;
}

std::string ScheduleObject::getName()
{
	return name;
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

std::string ScheduleObject::getTagsAsString()
{
	std::string s;

	int i = 0;
	for (auto const& e : tags)
	{
		if (i>0)
			s += ", ";
		s += e;
		i++;
		
	}
	return s;
}


void ScheduleObject::setTagsFromString(string value)
{
	std::set<std::string> temp;
	int i = 0;
	for (int j = 0; j < value.size(); j++)
		if (value[j] == ',')
		{
			temp.insert(value.substr(i, j - i));
			i = j + 2;
		}
	if (!value.empty())
		temp.insert(value.substr(i, value.size() - i));
	
	tags = temp;
}


void ScheduleObject::addTag(string value)
{
	tags.insert(value);
}

void ScheduleObject::removeTag(string value)
{
	tags.erase(value);
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

	ExcelFormat::XLSFormatManager fmt_mgr(xls);
	ExcelFormat::BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	//ExcelFormat::CellFormat fmt(fmt_mgr);
	//fmt.set_format_string(XLS_FORMAT_TEXT);

	//ExcelFormat::BasicExcelCell* cell;

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

