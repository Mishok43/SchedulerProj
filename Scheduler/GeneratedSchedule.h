#pragma once
#include "GlobalData.h"

#define SCHPARAMS 3

class FinalScheduleObject
{
public:
	
	FinalScheduleObject();
	FinalScheduleObject(Activity* activity, Classroom* classroom);
	string toString();

	Activity* getActivity();
	Classroom* getClassroom();

	friend std::ostream& operator<<(std::ostream& os, FinalScheduleObject& finalScheduleObject);
	friend std::istream& operator>>(std::istream& is, FinalScheduleObject& finalScheduleObject);

private:

	Activity* activity;
	Classroom* classroom;
};

class GeneratedSchedule
{
public:
	GeneratedSchedule();


	void reset();
	void generate();

	void initRules();
	
	vector<pair<string,string>> getErrors();
	bool isGenerated();

	void debugOutput(ScheduleObject* obj, const char * path);
	void exportXls(RuleData::objtype type, bool week, int startDay, int endDay, const char * path);

	friend std::ostream& operator<<(std::ostream& os, GeneratedSchedule& schedule);
	friend std::istream& operator>>(std::istream& is, GeneratedSchedule& schedule);

	float* process;
	int solutionsFound;

private:
	vector<vector<FinalScheduleObject>> hour;
	array<int, SCHPARAMS> params;

	vector<pair<vector<vector<FinalScheduleObject>>, array<int, SCHPARAMS>>> solutions;

	void updateSolutions();


};


extern GeneratedSchedule Schedule;




ref class MessagePrinter
{
private:

	// constructor to initialize a MessagePrinter object
public:
	MessagePrinter()
	{

	}

	//controls Thread that prints message
	void Print()
	{
		Schedule.generate();

	} // end method Print
}; // end class MessagePrinter  
