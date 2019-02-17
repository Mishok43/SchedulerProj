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
	void setId(std::string value);
	std::string getId();
	cli::array<System::String^>^ getParamRow();

	std::string getTagsAsString();

	virtual std::string getParam(int i) = 0;
	virtual int getParamNum() = 0;

	

protected:
	std::string id;
	std::string name;
	std::set<std::string> tags;
	std::vector<std::string> stringRules;
};


template <class T>
class ScheduleObjectContainer
{
public:

	void setVal(vector<T*> newValues)
	{
		values = vector<ScheduleObject*>();

		for (auto v : newValues)
			values.push_back(dynamic_cast<ScheduleObject*>(v));

		updateIds();
	}
	vector<T*> getVal()
	{
		vector<T*> val = vector<T*>();

		for (auto v : values)
			val.push_back(dynamic_cast<T*>(v));
		return val;
	}
	void updateIds()
	{
		for (auto v : values)
			if (v->getId().empty())
				updateId(v);
	}
	void updateId(ScheduleObject* obj)
	{
		std::function<string(char)> translit = [](char c) -> string
		{


			if (c >= '0' && c <= '9')
				return string(1, c);
			if (c >= 'a' && c <= 'z')
				return string(1, c);
			if (c >= 'A' && c <= 'Z')
				return string(1, c + 20);

			if (c >= 'À' && c <= 'ß')
				c = (c + 32);

			switch (c) {

			case 'à': return "a";
			case 'á': return "b";
			case 'â': return "v";
			case 'ã': return "g";
			case 'ä': return "d";
			case 'å': return "e";
				//case '¸': return "yo";
			case 'æ': return "j";
			case 'ç': return "z";
			case 'è': return "i";
			case 'é': return "y";
			case 'ê': return "k";
			case 'ë': return "l";
			case 'ì': return "m";
			case 'í': return "n";
			case 'î': return "o";
			case 'ï': return "p";
			case 'ð': return "r";
			case 'ñ': return "s";
			case 'ò': return "t";
			case 'ó': return "u";
			case 'ô': return "f";
			case 'õ': return "h";
			case 'ö': return "t";
			case '÷': return "c";
			case 'ø': return "sh";
			case 'ù': return "shi";
			case 'ú': return "\'";
			case 'û': return "y";
			case 'ü': return "i";
			case 'ý': return "e";
			case 'þ': return "yu";
			case 'ÿ': return "ya";
			default: return "_";
			}

		};

		string s = obj->getName();
		string id = "";
		for (auto c : s)
			if (c!=' ')
				id += c;

		string fullid = id;
		int postfix = 1;
		while (true)
		{
			bool only = true;
			for (auto v : values)
				if (v->getId() == fullid)
					only = false;
			if (only)
				break;
			postfix++;
			fullid = id + to_string(postfix);
		}

		obj->setId(fullid);
	}


private:
	vector<ScheduleObject*> values;

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

