#pragma once
#include "ScheduleObject.h"

class GlobalData
{
public:
	GlobalData();

	string messageBoxInput;

	//static vector<Classroom*> Classrooms;
	ScheduleObjectContainer<Classroom> Classrooms;
	ScheduleObjectContainer<Teacher> Teachers;
	Classroom* EditingClassroom;
	Teacher* EditingTeacher;

	vector<Classroom*> ClassroomsFormList;
	vector<Teacher*> TeachersFormList;

	TagRules ClassroomTagRules;
	TagRules TeacherTagRules;

	friend ostream& operator<<(ostream& os, GlobalData& gd);
	friend istream& operator>>(istream& is, GlobalData& gd);
};

extern GlobalData MainData;


