#pragma once
#include "ScheduleObject.h"
#include "ctime"

class GlobalData
{
public:
	GlobalData();
	

	tm StartDate;
	int Days;

	string messageBoxInput;

	//static vector<Classroom*> Classrooms;
	ScheduleObjectContainer<Classroom> Classrooms;
	ScheduleObjectContainer<Teacher> Teachers;
	ScheduleObjectContainer<Group> Groups;
	ScheduleObjectContainer<Activity> Activities;

	Classroom* EditingClassroom;
	Teacher* EditingTeacher;
	Group* EditingGroup;
	Activity* EditingActivity;

	vector<Classroom*> ClassroomsFormList;
	vector<Teacher*> TeachersFormList;
	vector<Group*> GroupsFormList;
	vector<Activity*> ActivitiesFormList;

	TagRules ClassroomTagRules;
	TagRules TeacherTagRules;
	TagRules GroupTagRules;
	TagRules ActivityTagRules;

	friend ostream& operator<<(ostream& os, GlobalData& gd);
	friend istream& operator>>(istream& is, GlobalData& gd);
};

extern GlobalData MainData;


