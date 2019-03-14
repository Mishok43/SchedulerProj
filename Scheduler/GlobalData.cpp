#include "GlobalData.h"


//vector<Classroom*> GlobalData::Classrooms;


GlobalData::GlobalData()
{
	Title = "Учебное заведение: 1 Семестр";

	std::time_t t = std::time(0);
	Rules::Settings.StartDate = *std::localtime(&t);
	Rules::Settings.Days = 70;

	Rules::Settings.ActivitiesPerDay = 9;

	for (int i = 0; i < 20; i++)
		Rules::Settings.ActivityStartTime[i] = 9 * 60 + (45 + 10) * i ;
	for (int i = 0; i < 20; i++)
		Rules::Settings.ActivityEndTime[i] = 9 * 60 + (45 + 10) * i + 45;

	for (int i = 0; i < 20; i++)
		if (Rules::Settings.ActivityStartTime[i] > (60 * 23 + 59))
			Rules::Settings.ActivityStartTime[i] = 60 * 23 + 59;
	for (int i = 0; i < 20; i++)
		if (Rules::Settings.ActivityEndTime[i] > (60 * 23 + 59))
			Rules::Settings.ActivityEndTime[i] = 60 * 23 + 59;

	//ScheduleObjectContainer<Classroom> GlobalData::Classrooms;
	//Classroom * GlobalData::EditingClassroom = nullptr;
}


ostream& operator<<(ostream& os, GlobalData& dt)
{
	os << dt.Title << endl;
	os << dt.PassManager << endl;
	os << dt.PassTeacher << endl;
	os << Rules::Settings;
	os << dt.Classrooms;
	os << dt.ClassroomTagRules;
	os << dt.Teachers;
	os << dt.TeacherTagRules;
	os << dt.Groups;
	os << dt.GroupTagRules;
	os << dt.Activities;
	os << dt.ActivityTagRules;
	return os;
}

istream& operator>>(istream & is, GlobalData& dt)
{
	getline(is, dt.Title);
	getline(is, dt.PassManager);
	getline(is, dt.PassTeacher);
	is >> Rules::Settings;
	is >> dt.Classrooms;
	is >> dt.ClassroomTagRules;
	is >> dt.Teachers;
	is >> dt.TeacherTagRules;
	is >> dt.Groups;
	is >> dt.GroupTagRules;
	is >> dt.Activities;
	is >> dt.ActivityTagRules;
	return is;
}

GlobalData::accesstype GlobalData::Access;
 string GlobalData::Path;


string GlobalData::MessageBoxInput;
bool GlobalData::MessageBoxBool;

Classroom* GlobalData::EditingClassroom;
Teacher* GlobalData::EditingTeacher;
Group* GlobalData::EditingGroup;
Activity* GlobalData::EditingActivity;

vector<Classroom*> GlobalData::ClassroomsFormList;
vector<Teacher*> GlobalData::TeachersFormList;
vector<Group*> GlobalData::GroupsFormList;
vector<Activity*> GlobalData::ActivitiesFormList;



GlobalData MainData;
ScheduleObjectContainer<Group>& Activity::GlobalGroups = MainData.Groups;
ScheduleObjectContainer<Teacher>& Activity::GlobalTeachers = MainData.Teachers;
