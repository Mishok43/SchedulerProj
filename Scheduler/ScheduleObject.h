#pragma once

#include "Excel/ExcelFormat.h"
#include <string>
#include <set>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include "Rules.h"




class ScheduleObject
{
public:
	ScheduleObject(std::string name,std::string description, std::set<std::string> tags);
	void setName(std::string value);
	std::string getName();
	void setDescription(std::string value);
	std::string getDescription();
	Rules& getRules();
	cli::array<System::String^>^ getParamRow();

	std::string getTagsAsString();
	void setTagsFromString(string value);

	

	void addTag(string value);
	void removeTag(string value);

	virtual std::string getParam(int i) = 0;
	virtual int getParamNum() = 0;

	virtual void ostreamF(std::ostream& os) { std::cout << "oops"; };
	virtual void istreamF(std::istream& is) {};

	friend string setToString(set<string> list);
	friend set<string> stringToSet(string str);

	friend std::ostream& operator<<(std::ostream& os, ScheduleObject& obj);
	friend std::istream& operator>>(std::istream& is, ScheduleObject& obj);

protected:

	std::string name;
	std::string descripton;
	std::set<std::string> tags;
	Rules rules;
	
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

	}
	vector<T*> getVal()
	{
		vector<T*> val = vector<T*>();

		for (auto v : values)
			val.push_back(dynamic_cast<T*>(v));
		return val;
	}
	
	void add(T* obj)
	{
		values.push_back(dynamic_cast<ScheduleObject*>(obj));
	}

	void erase(T* obj)
	{
		ScheduleObject* casted = dynamic_cast<ScheduleObject*>(obj);

		int pos = -1;
		for (int i = 0; i < values.size(); i++)
			if (casted == values[i])
				pos = i;
		values.erase(values.begin()+pos);
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

		string temp;

		int n;

		soc.values.clear();

		getline(is,temp);
		n = atoi(temp.c_str());

		T* obj;
		for (int i = 0; i < n; i++) 
		{
			obj = new T();
			is >> *obj;
			soc.values.push_back(dynamic_cast<ScheduleObject*>(obj));
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
	static void Classroom::ClassroomsToExcel(vector<Classroom*> v,const char * path);

	Classroom();
	Classroom(std::string name,std::string description, std::set<std::string> tags, int capacity);
	int getCapacity();
	void setCapacity(int value);


	virtual void ostreamF(std::ostream& os);
	virtual void istreamF(std::istream& is);
	
	virtual std::string getParam(int i);
	virtual int getParamNum();
private:
	int capacity;
	
};

