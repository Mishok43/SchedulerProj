#pragma once
#include "GlobalData.h"


class FinalScheduleObject
{
public:
	FinalScheduleObject(Activity* activity, Classroom* classroom)
	{
		this->activity = activity;
		this->classroom = classroom;
	}

	string toString()
	{
		string s = activity->getName();
		s += " " + activity->getTeacher()->getName();
		s += " " + classroom->getName();
		return s;
	}
private:

	Activity* activity;
	Classroom* classroom;
};

class GeneratedSchedule
{
public:
	GeneratedSchedule();
	GeneratedSchedule(GlobalData mainData);


	friend std::ostream& operator<<(std::ostream& is, GeneratedSchedule& schedule);

	vector<vector<FinalScheduleObject>> hour;
private:
	
};

