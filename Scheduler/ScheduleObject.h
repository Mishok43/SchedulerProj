#pragma once

#include "Excel/ExcelFormat.h"
#include <string>
#include <set>
#include <vector>




class ScheduleObject
{
public:
	ScheduleObject(std::string name, std::set<std::string> tags);
	void setName(std::string value);
	std::string getName();
	std::string getId();
	cli::array<System::String^>^ getParamRow();

	std::string getTagsAsString();

	virtual std::string getParam(int i)=0;
	virtual int getParamNum()=0;

	

protected:
	std::string id;
	std::string name;
	std::set<std::string> tags;
	std::vector<std::string> stringRules;
};


class Classroom : public ScheduleObject
{
public:


	static std::vector<Classroom*> Classroom::ExcelToClassrooms(const char * path);

	Classroom(std::string name, std::set<std::string> tags, int capacity);
	int getCapacity();
	void setCapacity(int value);

	virtual std::string getParam(int i);
	virtual int getParamNum();
private:
	int capacity;
};


