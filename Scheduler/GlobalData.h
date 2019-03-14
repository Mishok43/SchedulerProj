#pragma once
#include "ScheduleObject.h"
#include "ctime"

class GlobalData
{
public:
	enum accesstype {STUDENT, TEACHER, MANAGER };
	static accesstype Access;
	static string Path;


	string PassTeacher;
	string PassManager;

	GlobalData();
	
	string Title;


	static string MessageBoxInput;
	static bool MessageBoxBool;

	//static vector<Classroom*> Classrooms;
	ScheduleObjectContainer<Classroom> Classrooms;
	ScheduleObjectContainer<Teacher> Teachers;
	ScheduleObjectContainer<Group> Groups;
	ScheduleObjectContainer<Activity> Activities;

	static Classroom* EditingClassroom;
	static Teacher* EditingTeacher;
	static Group* EditingGroup;
	static Activity* EditingActivity;

	static vector<Classroom*> ClassroomsFormList;
	static vector<Teacher*> TeachersFormList;
	static vector<Group*> GroupsFormList;
	static vector<Activity*> ActivitiesFormList;

	TagRules ClassroomTagRules;
	TagRules TeacherTagRules;
	TagRules GroupTagRules;
	TagRules ActivityTagRules;



	friend ostream& operator<<(ostream& os, GlobalData& gd);
	friend istream& operator>>(istream& is, GlobalData& gd);
};

extern GlobalData MainData;


