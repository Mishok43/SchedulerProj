#include "ScheduleObject.h"


char translit(char c)
{

	if (c >= '0' && c <= '9')
		return c;
	if (c >= 'a' && c <= 'z')
		return c;
	if (c >= 'A' && c <= 'Z')
		return (c + 20);

	if (c >= '�' && c <= '�')
		return (c + 32);

	switch (c) {

	case '�': return 'a';
	case '�': return 'b';
	case '�': return 'v';
	case '�': return 'g';
	case '�': return 'd';
	case '�': return 'e';
	//case '�': return 'yo';
	case '�': return 'j';
	case '�': return 'z';
	case '�': return 'i';
	case '�': return 'Y';
	case '�': return 'k';
	case '�': return 'l';
	case '�': return 'm';
	case '�': return 'n';
	case '�': return 'o';
	case '�': return 'p';
	case '�': return 'r';
	case '�': return 's';
	case '�': return 't';
	case '�': return 'u';
	case '�': return 'f';
	case '�': return 'h';
	case '�': return 't';
	case '�': return 'c';
	case '�': return 's';
	case '�': return 'S';
	case '�': return 'I';
	case '�': return 'y';
	case '�': return 'i';
	case '�': return 'e';
	case '�': return 'Y';
	case '�': return 'A';
	default: return '_';
	}
		
}

std::set<std::string> splitToSet(std::string s)
{
	std::set<std::string> temp;
	int i = 0;
	for (int j=0;j<s.size();j++)
		if (s[j] == ',')
		{
			temp.insert(s.substr(i, j - i ));
			i = j + 2;
		}

	temp.insert(s.substr(i, s.size() - i));
	return temp;
		

}

ScheduleObject::ScheduleObject(std::string name, std::set<std::string> tags)
{
	setName(name);
	this->tags = tags;
}

void ScheduleObject::setName(std::string value)
{
	string s;

	for (auto it = value.begin(); it != value.end(); ++it)
		if (*it !=' ')
			s += translit(*it);
	id = s;
	name = value;
}

std::string ScheduleObject::getName()
{
	return name;
}

std::string ScheduleObject::getId()
{
	return id;
}



cli::array<System::String^>^ ScheduleObject::getParamRow()
{
	cli::array<System::String^>^ a = gcnew cli::array<System::String^>(getParamNum());
	for (int i = 0; i < getParamNum(); i++)
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
		string tags = sheet->Cell(i, 2)->GetValue();

		v.push_back(new Classroom(name, splitToSet(tags), capacity));
		++i;
		
	}
		
	return v;
}




Classroom::Classroom(std::string name, std::set<std::string> tags, int capacity) : ScheduleObject(name, tags)
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
	case 0: s = id; break;
	case 1: s = name; break;
	case 2: s = std::to_string(capacity); break;
	case 3: s = stringRules.empty() ? "" : "+"; break;
	case 4: s = getTagsAsString(); break;
	}
		


	return s;
}
int Classroom::getParamNum()
{
	return 5;
}