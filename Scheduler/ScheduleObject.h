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
	void setId(int value);
	int getId();
	void setName(std::string value);
	std::string getName();
	void setDescription(std::string value);
	std::string getDescription();
	Rules& getRules();
	cli::array<System::String^>^ getParamRow();

	set<string> getTags();
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
	int id;
	std::string name;
	std::string descripton;
	std::set<std::string> tags;
	Rules rules;
	
};


template <class T>
class ScheduleObjectContainer
{
public:

	void updateIds()
	{
		for (int i = 0; i < values.size(); i++)
		{
			values[i]->setId(i);
		}
	}

	map<string, vector<int>> getNameMap()
	{
		map<string, vector<int>> m;


		m.insert(pair<string, vector<int>>("бяе", vector<int>()));

		for (auto v: values)
		{
			string s = v->getName();
			int id = v->getId();

			m["бяе"].push_back(id);

			if (m.find(s) == m.end())
				m.insert(pair < string, vector<int>>(s, vector<int>{ id }));
			else
				m[s].push_back(id);


			for (auto tag : v->getTags())
			{
				if (m.find(tag) == m.end())
					m.insert(pair < string, vector<int>>(tag, vector<int>{ id }));
				else
					m[tag].push_back(id);
			}
		}


		return m;
	}

	void updateRules()
	{
		for (auto v : values)
			v->getRules().update();
	}


	void uniteWithTagRules(TagRules& t)
	{
		map<string, Rules> m = t.getMap();
		for (auto v : values)
		{
			if (!(m.find("бяе")==m.end()))
				v->getRules().getData().and(m["бяе"].getData());
			for (auto tag : v->getTags())
			{
				if (!(m.find(tag) == m.end()))
					v->getRules().getData().and(m[tag].getData());
			}
		}
			
				
	}

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

	T* getByPos(int pos)
	{
		return dynamic_cast<T*>(values[pos]);
	}

	int getPos(T* obj)
	{
		int i = 0;
		for (auto v : values)
		{
			if (v == obj)
				return i;
			i++;
		}
		
		return -1;
	}

	T* getByName(string name)
	{
		for (auto v : values)
			if (v->getName() == name)
				return dynamic_cast<T*>(v);
		return nullptr;
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
		n = stoi(temp);

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


	static std::vector<Classroom*> ExcelToClassrooms(const char * path);
	static void ClassroomsToExcel(vector<Classroom*> v,const char * path);

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


class Teacher : public ScheduleObject
{
public:

	static std::vector<Teacher*> ExcelToTeachers(const char * path);
	static void TeachersToExcel(vector<Teacher*> v, const char * path);

	Teacher();
	Teacher(std::string name, std::string description, std::set<std::string> tags);

	std::string getShortName();

	virtual void ostreamF(std::ostream& os);
	virtual void istreamF(std::istream& is);

	virtual std::string getParam(int i);
	virtual int getParamNum();
};


class Group : public ScheduleObject
{
public:


	static std::vector<Group*> ExcelToGroups(const char * path);
	static void GroupsToExcel(vector<Group*> v, const char * path);

	Group();
	Group(std::string name, std::string description, std::set<std::string> tags, int size);
	int getSize();
	void setSize(int value);


	virtual void ostreamF(std::ostream& os);
	virtual void istreamF(std::istream& is);

	virtual std::string getParam(int i);
	virtual int getParamNum();
private:
	int size;

};



class Activity : public ScheduleObject
{
public:
	static ScheduleObjectContainer<Teacher>& GlobalTeachers;
	static ScheduleObjectContainer<Group>& GlobalGroups;

	static std::vector<Activity*> ExcelToActivities(const char * path);
	static void ActivitiesToExcel(vector<Activity*> v, const char * path);

	Activity();
	Activity(std::string name, std::string description, std::set<std::string> tags, string teacherName, std::set<string> groupNames, int hours);
	int getHours();
	void setHours(int value);
	Teacher* getTeacher();
	string getTeacherName();
	string getTeacherShortName();
	set<Group*> getGroups();
	string getGroupsAsString();

	virtual void ostreamF(std::ostream& os);
	virtual void istreamF(std::istream& is);
	


	virtual std::string getParam(int i);
	virtual int getParamNum();
private:
	Teacher* teacher;
	set<Group*> groups;
	int hours;


};

