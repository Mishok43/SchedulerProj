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
	cli::array<System::String^>^ getParamRow();

	std::string getTagsAsString();

	virtual std::string getParam(int i) = 0;
	virtual int getParamNum() = 0;

	virtual void ostreamF(std::ostream& os) const { std::cout << "oops"; };
	virtual void istreamF(std::istream& is) {};

	friend std::ostream& operator<<(std::ostream& os, const ScheduleObject& obj);
	friend std::istream& operator>>(std::istream& is, ScheduleObject& obj);

protected:

	std::string name;
	std::string descripton;
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

	}
	vector<T*> getVal()
	{
		vector<T*> val = vector<T*>();

		for (auto v : values)
			val.push_back(dynamic_cast<T*>(v));
		return val;
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
			//soc.values.push_back(dynamic_cast<ScheduleObject*>(new T()));
			//is >> *dynamic_cast<T*>(soc.values[i]);

			obj = new T();
			is >> *obj;
			soc.values.push_back(dynamic_cast<ScheduleObject*>(obj));
			//soc.values.push_back(dynamic_cast<ScheduleObject*>(obj));
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

	Classroom();
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

