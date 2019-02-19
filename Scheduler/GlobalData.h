#pragma once
#include "ScheduleObject.h"

class GlobalData
{
public:
	GlobalData();

	

	//static vector<Classroom*> Classrooms;
	ScheduleObjectContainer<Classroom> Classrooms;
	Classroom* EditingClassroom;

	friend ostream& operator<<(ostream& os, const GlobalData& gd);
	friend istream& operator>>(istream& is, GlobalData& gd);
};

extern GlobalData MainData;


