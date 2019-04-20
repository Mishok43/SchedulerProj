#pragma once
#include "GlobalData.h"

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
	void generate(bool simple);
	void initRules();
	
	vector<pair<string,string>> getErrors();
	bool isGenerated();

	void debugOutput(ScheduleObject* obj, const char * path);
	void exportXls(RuleData::objtype type, bool week, int startDay, int endDay, const char * path);

	friend std::ostream& operator<<(std::ostream& os, GeneratedSchedule& schedule);
	friend std::istream& operator>>(std::istream& is, GeneratedSchedule& schedule);

	
private:
	vector<vector<FinalScheduleObject>> hour;
};


extern GeneratedSchedule Schedule;
