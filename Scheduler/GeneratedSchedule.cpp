#include "GeneratedSchedule.h"
#include <random>

GeneratedSchedule::GeneratedSchedule()
{
}


GeneratedSchedule::GeneratedSchedule(GlobalData mainData)
{
	vector<Activity*> act = mainData.Activities.getVal();
	vector<Classroom*> cls = mainData.Classrooms.getVal();
	int n = Rules::Settings.Days * Rules::Settings.ActivitiesPerDay;

	for (int i = 0; i <n;i++)
	{
		hour.push_back(vector<FinalScheduleObject>());
	}

	
	

	for (int i = 0; i < act.size(); i++)
	{


		for (int j = 0; j < act[i]->getHours(); j++)
		{
			FinalScheduleObject f = FinalScheduleObject(act[i], cls[rand()%cls.size()]);
			hour[rand() % n].push_back(f);
		}

	}
	
}


ostream& operator<<(ostream& os, GeneratedSchedule& generatedSchedule)
{

	for (int i = 0; i < generatedSchedule.hour.size(); i++)
	{
		os << Rules::activityHourToStringDebug(i) << endl;
		for (int j = 0; j < generatedSchedule.hour[i].size(); j++)
		{
			os << generatedSchedule.hour[i][j].toString() << endl;
		}
	}
	return os;
}
