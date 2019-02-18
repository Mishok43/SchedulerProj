#pragma once
#include "ScheduleObject.h"

class GlobalData
{
public:
	GlobalData();


	//static vector<Classroom*> Classrooms;
	static ScheduleObjectContainer<Classroom> Classrooms;
	static Classroom* EditingClassroom;
};

