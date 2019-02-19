#include "GlobalData.h"


//vector<Classroom*> GlobalData::Classrooms;


GlobalData::GlobalData()
{
	//ScheduleObjectContainer<Classroom> GlobalData::Classrooms;
	//Classroom * GlobalData::EditingClassroom = nullptr;
}

ostream& operator<<(ostream& os, const GlobalData& dt)
{
	os << dt.Classrooms;
	return os;
}

istream& operator>>(istream & is, GlobalData& dt)
{
	is >> dt.Classrooms;
	return is;
}

GlobalData MainData;