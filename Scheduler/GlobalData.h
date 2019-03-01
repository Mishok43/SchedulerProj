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
	ScheduleObjectContainer<Group> Groups;

	Classroom* EditingClassroom;
	Teacher* EditingTeacher;
	Group* EditingGroup;

	vector<Classroom*> ClassroomsFormList;
	vector<Teacher*> TeachersFormList;
	vector<Group*> GroupsFormList;

	TagRules ClassroomTagRules;
	TagRules TeacherTagRules;
	TagRules GroupTagRules;

	friend ostream& operator<<(ostream& os, GlobalData& gd);
	friend istream& operator>>(istream& is, GlobalData& gd);
};

extern GlobalData MainData;


