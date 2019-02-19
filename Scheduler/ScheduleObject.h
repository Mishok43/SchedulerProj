#pragma once

#include "Excel/ExcelFormat.h"
#include <string>
#include <set>
#include <vector>
#include <msclr\marshal_cppstd.h>





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

	virtual void ostreamF(std::ostream& os) const { std::cout << "oops"; };
	virtual void istreamF(std::istream& is) const {};

	friend std::ostream& operator<<(std::ostream& os, const ScheduleObject& obj);
	friend std::istream& operator>>(std::ostream& is, ScheduleObject& obj);

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

			if (c >= '�' && c <= '�')
				c = (c + 32);

			switch (c) {

			case '�': return "a";
			case '�': return "b";
			case '�': return "v";
			case '�': return "g";
			case '�': return "d";
			case '�': return "e";
				//case '�': return "yo";
			case '�': return "j";
			case '�': return "z";
			case '�': return "i";
			case '�': return "y";
			case '�': return "k";
			case '�': return "l";
			case '�': return "m";
			case '�': return "n";
			case '�': return "o";
			case '�': return "p";
			case '�': return "r";
			case '�': return "s";
			case '�': return "t";
			case '�': return "u";
			case '�': return "f";
			case '�': return "h";
			case '�': return "t";
			case '�': return "c";
			case '�': return "sh";
			case '�': return "shi";
			case '�': return "\'";
			case '�': return "y";
			case '�': return "i";
			case '�': return "e";
			case '�': return "yu";
			case '�': return "ya";
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
		{\
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

	T* getObjectById(string id)
	{
		for (auto v : values)
			if (v->getId() == id)
				return dynamic_cast<T*>(v);
		return nullptr;
	}


	friend ostream& operator<<(ostream& os, const ScheduleObjectContainer& soc)
	{
		
		int n = soc.values.size();

		os << n << endl;
		for (int i=0;i<n;i++)
			os << *dynamic_cast<T*>(soc.values[i]);
		return os;
	}
	friend istream& operator>>(istream& is, ScheduleObjectContainer& soc)
	{
		
		int n;
		soc.values.clear();

		is >> n;

		T* obj;
		for (int i = 0; i < n; i++) 
		{
			is >> *obj;
			soc.push_back(dynamic_cast<ScheduleObject*>(obj));
		}
			
			
		return is;
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


	virtual void ostreamF(std::ostream& os) const;
	virtual void istreamF(std::istream& is);
	
	virtual std::string getParam(int i);
	virtual int getParamNum();
private:
	int capacity;
	
};

