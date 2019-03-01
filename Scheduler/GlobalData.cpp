#include "GlobalData.h"


//vector<Classroom*> GlobalData::Classrooms;


GlobalData::GlobalData()
{
	//ScheduleObjectContainer<Classroom> GlobalData::Classrooms;
	//Classroom * GlobalData::EditingClassroom = nullptr;
}

ostream& operator<<(ostream& os, GlobalData& dt)
{
	os << dt.Classrooms;
	os << dt.ClassroomTagRules;
	os << dt.Teachers;
	os << dt.TeacherTagRules;
	os << dt.Groups;
	os << dt.GroupTagRules;
	return os;
}

istream& operator>>(istream & is, GlobalData& dt)
{
	is >> dt.Classrooms;
	is >> dt.ClassroomTagRules;
	is >> dt.Teachers;
	is >> dt.TeacherTagRules;
	is >> dt.Groups;
	is >> dt.GroupTagRules;
	return is;
}

GlobalData MainData;