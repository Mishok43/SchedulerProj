#include "GlobalData.h"


//vector<Classroom*> GlobalData::Classrooms;

ScheduleObjectContainer<Classroom> GlobalData::Classrooms;
Classroom * GlobalData::EditingClassroom = nullptr;
GlobalData::GlobalData()
{

}
