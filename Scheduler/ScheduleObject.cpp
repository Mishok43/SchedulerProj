#include "ScheduleObject.h"





ScheduleObject::ScheduleObject(std::string name, std::set<std::string> tags)
{
	this->name = name;
	this->tags = tags;
}

void ScheduleObject::setName(std::string value)
{
	id = value;
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

	for (auto const& e : tags)
	{
		s += e;
		s += ", ";
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

	
	for (int i = 1; true; i++)
	{
		
		ExcelFormat::BasicExcelCell* cell = sheet->Cell(i, 0);
		
		string name = cell->GetValue();

		if (name.empty())
			break;

		v.push_back(new Classroom(name, {}, 4));
		
	}
		

	/*
	ExcelFormat::BasicExcelCell* cell = sheet->Cell(0, 0);
	//cell->SetFormat(fmt);
	//const char* s = sheet->Cell(1, 0)->GetString();
	//std::wstring s = std::wstring();
	

	
	std::wstring s2 = std::wstring(cell->GetWString());
	std::wstring s = L"Идентификатор";

	std::string ss = wstring_to_utf16(s);

	 int o = int('И');
	//std::wstring s = L"аваыаыва";
	OutputDebugStringW(std::to_wstring(o).c_str());

	o = int(s[0]);
	OutputDebugStringW(std::to_wstring(o).c_str());
	//OutputDebugStringW(stemp.c_str());

	ss = "Идентификатор";
	v.push_back(new Classroom(wstring_to_utf16(s), {},4));
	v.push_back(new Classroom(wstring_to_utf16(s2), {}, 4));

	//std::wstring s = std::wstring(cell->GetWString());

	//v.push_back(new Classroom(std::string(s.begin(),s.end()), {},4));
	*/

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