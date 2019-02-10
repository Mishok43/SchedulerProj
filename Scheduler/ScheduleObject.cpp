#include "ScheduleObject.h"
#include <codecvt>
#include <locale>


// convert UTF-16 string to wstring
std::wstring utf16_to_wstring(const std::string& str)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> myconv;
	return myconv.from_bytes(str);
}

// convert wstring to UTF-16 string
std::string wstring_to_utf16(const std::wstring& str)
{
	//std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> myconv;
	//return myconv.to_bytes(str);


	//std::codecvt_utf8<char32_t> myconv;
	//return myconv.to_bytes(str);
	typedef std::codecvt_utf8<wchar_t>
		convert_typeX;
	std::wstring_convert<convert_typeX, wchar_t>
		converterX;
	return converterX.to_bytes(str);
}


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
	v.push_back(new Classroom("622", {}, 5));
    v.push_back(new Classroom("321", { "A","B" }, 44));

	ExcelFormat::BasicExcel xls(path);

	ExcelFormat::XLSFormatManager fmt_mgr(xls);
	ExcelFormat::BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	ExcelFormat::CellFormat fmt(fmt_mgr);
	fmt.set_format_string(XLS_FORMAT_TEXT);

	ExcelFormat::BasicExcelCell* cell = sheet->Cell(0, 0);
	//cell->SetFormat(fmt);
	//const char* s = sheet->Cell(1, 0)->GetString();
	//std::wstring s = std::wstring();
	
	std::wstring s = std::wstring(cell->GetWString());
	s = L"Идентификатор";
	std::string ss = wstring_to_utf16(s);

	unsigned int o = (unsigned int)ss[0];
	//std::wstring s = L"аваыаыва";
	OutputDebugStringW(std::to_wstring(o).c_str());
	//OutputDebugStringW(stemp.c_str());

	ss = "Идентификатор";
	v.push_back(new Classroom(wstring_to_utf16(s), {},4));
	v.push_back(new Classroom(ss, {}, 4));

	//std::wstring s = std::wstring(cell->GetWString());

	//v.push_back(new Classroom(std::string(s.begin(),s.end()), {},4));


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
	case 0: s = name; break;
	case 1: s = std::to_string(capacity); break;
	case 2: s = stringRules.empty() ? "" : "+"; break;
	case 3: s = getTagsAsString(); break;
	}
		


	return s;
}
int Classroom::getParamNum()
{
	return 4;
}