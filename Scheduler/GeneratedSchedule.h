#pragma once
#include "GlobalData.h"

#define SCHPARAMS 4
#define MAXSOLUTIONS 7

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
	void exportXls(int sol, RuleData::objtype type, bool week, int startDay, int endDay, const char * path);

	friend std::ostream& operator<<(std::ostream& os, GeneratedSchedule& schedule);
	friend std::istream& operator>>(std::istream& is, GeneratedSchedule& schedule);

	float* process;
	long long  solutionsFound;

	bool onPause;
	bool ending;
	bool doneEnding;

	void chooseSolution(int sol);
	
	
	vector<array<float, SCHPARAMS>> getSolutionsParams();
private:
	vector<vector<FinalScheduleObject>> hour;

	vector<vector<FinalScheduleObject>> tempHour;

	array<int, SCHPARAMS> params;

	vector<pair<vector<vector<FinalScheduleObject>>, array<float, SCHPARAMS>>> solutions;

	

	void updateSolutions();


};


extern GeneratedSchedule Schedule;




ref class ThreadHelper
{
private:

public:
	ThreadHelper()
	{

	}

	void Run()
	{
		Schedule.generate();
	}
};  
