#include "GeneratedSchedule.h"
#include <random>

FinalScheduleObject::FinalScheduleObject()
{

}
FinalScheduleObject::FinalScheduleObject(Activity* activity, Classroom* classroom)
{
	this->activity = activity;
	this->classroom = classroom;
}

string FinalScheduleObject::toString()
{
	string s = activity->getName();
	s += " " + activity->getTeacher()->getName();
	s += " " + classroom->getName();
	return s;
}

Activity* FinalScheduleObject::getActivity()
{
	return activity;
}
Classroom* FinalScheduleObject::getClassroom()
{
	return classroom;
}

std::ostream & operator<<(std::ostream & os, FinalScheduleObject & finalScheduleObject)
{
	os << MainData.Activities.getPos(finalScheduleObject.activity) << endl;
	os << MainData.Classrooms.getPos(finalScheduleObject.classroom) << endl;
	return os;
}

std::istream & operator>>(std::istream & is, FinalScheduleObject & finalScheduleObject)
{
	string temp;
	getline(is, temp);
	finalScheduleObject.activity = MainData.Activities.getByPos(stoi(temp));
	getline(is, temp);
	finalScheduleObject.classroom = MainData.Classrooms.getByPos(stoi(temp));
	return is;
	
}

GeneratedSchedule::GeneratedSchedule()
{
	
	
}


void GeneratedSchedule::initRules()
{
	


}
bool GeneratedSchedule::isGenerated()
{
	return !hour.empty();
}
void GeneratedSchedule::reset()
{
	hour.clear();
}

void GeneratedSchedule::generate()
{

	reset();

	vector<Activity*> act = MainData.Activities.getVal();



	vector<Classroom*> cls = MainData.Classrooms.getVal();
	int n = Rules::Settings.Days * Rules::Settings.ActivitiesPerDay;

	for (int i = 0; i < n; i++)
	{
		hour.push_back(vector<FinalScheduleObject>());
	}

	
	for (int i = 0; i < act.size(); i++)
	{


		for (int j = 0; j < act[i]->getHours(); j++)
		{
			FinalScheduleObject f = FinalScheduleObject(act[i], cls[rand() % cls.size()]);
			hour[rand() % n].push_back(f);
		}

	}
}


void GeneratedSchedule::debugOutput(ScheduleObject* obj, const char * path)
{

	initRules();

	ExcelFormat::BasicExcel xls;
	xls.New(1);
	ExcelFormat::BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	ExcelFormat::XLSFormatManager fmt_mgr(xls);

	ExcelFormat::CellFormat fmt(fmt_mgr);
	fmt.set_wrapping(true);

	for (int i = 0; i < Rules::Settings.Days; i++)
	{
		sheet->Cell(0, 1 + i)->SetValue(Rules::dayToStringDebug(i));
		sheet->Cell(0, 1 + i)->SetFormat(fmt);
	}

	for (int j = 0; j < Rules::Settings.ActivitiesPerDay; j++)
	{
		sheet->Cell(1 + j, 0)->SetValue(to_string(j));
	}




	for (int i = 0; i < Rules::Settings.Days; i++)
		for (int j = 0; j < Rules::Settings.ActivitiesPerDay; j++)
		{
			fmt.set_background(MAKE_COLOR2(obj->getRules().getData().canDayDaytime(i, j) ? ExcelFormat::EGA_RED : ExcelFormat::EGA_WHITE, 0));
			sheet->Cell(j + 1, i + 1)->SetFormat(fmt);
		}




	vector<Group*> groups = MainData.Groups.getVal();
	for (int i = 0; i < groups.size(); i++)
	{
		fmt.set_background(MAKE_COLOR2(obj->getRules().getData().canObj(RuleData::GROUPOBJ, i) ? ExcelFormat::EGA_RED : ExcelFormat::EGA_WHITE, 0));

		sheet->Cell(21 + 1, i)->SetValue(groups[i]->getName());
		sheet->Cell(21 + 2, i)->SetFormat(fmt);
	}

	vector<Teacher*> teachers = MainData.Teachers.getVal();
	for (int i = 0; i < teachers.size(); i++)
	{
		fmt.set_background(MAKE_COLOR2(obj->getRules().getData().canObj(RuleData::TEACHEROBJ, i) ? ExcelFormat::EGA_RED : ExcelFormat::EGA_WHITE, 0));

		sheet->Cell(21 + 3, i)->SetValue(teachers[i]->getName());
		sheet->Cell(21 + 4, i)->SetFormat(fmt);
	}

	vector<Activity*> activities = MainData.Activities.getVal();
	for (int i = 0; i < activities.size(); i++)
	{
		fmt.set_background(MAKE_COLOR2(obj->getRules().getData().canObj(RuleData::ACTIVITYOBJ, i) ? ExcelFormat::EGA_RED : ExcelFormat::EGA_WHITE, 0));

		sheet->Cell(21 + 5, i)->SetValue(activities[i]->getName());
		sheet->Cell(21 + 6, i)->SetFormat(fmt);
	}

	vector<Classroom*> classrooms = MainData.Classrooms.getVal();
	for (int i = 0; i < classrooms.size(); i++)
	{
		fmt.set_background(MAKE_COLOR2(obj->getRules().getData().canObj(RuleData::CLASSROOMOBJ, i) ? ExcelFormat::EGA_RED : ExcelFormat::EGA_WHITE, 0));

		sheet->Cell(21 + 7, i)->SetValue(classrooms[i]->getName());
		sheet->Cell(21 + 8, i)->SetFormat(fmt);
	}

	sheet->Cell(21 + 9, 0)->SetValue("Max hours per week:");
	sheet->Cell(21 + 9, 1)->SetValue(to_string(obj->getRules().getData().getMaxPerWeek()));


	xls.SaveAs(path);
}

void GeneratedSchedule::exportXls(RuleData::objtype type, bool week, int startDay, int endDay, const char * path)
{
	ExcelFormat::BasicExcel xls;
	xls.New(1);
	ExcelFormat::BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	ExcelFormat::XLSFormatManager fmt_mgr(xls);

	ExcelFormat::CellFormat fmt(fmt_mgr);
	fmt.set_wrapping(true);

	vector<string> names;

	switch (type)
	{
	case RuleData::GROUPOBJ :
		for (auto o : MainData.Groups.getVal())
			names.push_back(o->getName());
		break;
	case RuleData::TEACHEROBJ:
		for (auto o : MainData.Teachers.getVal())
			names.push_back(o->getName());
		break;
	case RuleData::ACTIVITYOBJ:
		for (auto o : MainData.Activities.getVal())
			names.push_back(o->getName());
		break;
	case RuleData::CLASSROOMOBJ:
		for (auto o : MainData.Classrooms.getVal())
			names.push_back(o->getName());
		break;
	}

	sheet->Cell(0, 0)->SetValue(MainData.Title);
	sheet->Cell(1, 0)->SetValue(week ? "День" : "Дата/День");
	sheet->Cell(1, 1)->SetValue("Пара");
	sheet->Cell(1, 2)->SetValue("Время");

	for (int i = 0; i < names.size(); i++)
	{
		sheet->Cell(1, i + 3)->SetValue(names[i]);
		sheet->SetColWidth(i + 3, 21 * 300);
	}
		

	struct MyCell {
	public:
		MyCell(Activity* a, Classroom* c, tm t)
		{
			act = a;
			cl.insert(pair<Classroom*, vector<tm>>(c, vector<tm>{t}));
		}

		void add(Classroom* c, tm t)
		{
			if (cl.find(c) == cl.end())
			{
				cl.insert(pair<Classroom*, vector<tm>>(c, vector<tm>{t}));
			}
			else
			{
				cl[c].push_back(t);
			}

			time = t;
		}

		string toString(bool activity, bool teacher, bool groups, bool classroom, bool date)
		{
			string s;
			if (activity)
				s += act->getName() + "\n";
			if (teacher)
				s += act->getTeacher()->getShortName() + "\n";
			if (groups)
				s += act->getGroupsAsString() + (classroom ? "\n" : "");

			bool mustAddLine = false;

			if (classroom)
				for (map<Classroom*, vector<tm>>::iterator it = cl.begin(); it != cl.end(); ++it)
				{
					if (mustAddLine)
						s += "\n";
					mustAddLine = true;
					
					s += it->first->getName();
					if (date)
					{
						s += ": ";
						for (auto o : it->second)
						{
							string m1 = to_string(o.tm_mday);
							if (m1.length() == 1)
								m1 = "0" + m1;
							string m2 = to_string(o.tm_mon + 1);
							if (m2.length() == 1)
								m2 = "0" + m2;
							s += m1 + "." + m2 + " ";
						}
					}
					
				
				}
			return s;
		}

		Activity* act;
		map<Classroom*,vector<tm>> cl;
		tm time;
		
	};

	int n = week ? 7 * Rules::Settings.ActivitiesPerDay : Rules::Settings.Days*Rules::Settings.ActivitiesPerDay;

	vector<string> weekDayNames = vector<string>{ "Понедельник", "Вторник", "Среда","Четверг","Пятница","Суббота","Воскресенье" };



	vector<vector<vector<MyCell>>> arr;
	
	for (int i = 0; i < n; i++)
	{
		arr.push_back(vector<vector<MyCell>>());
		for (int j = 0; j < names.size(); j++)
			arr[i].push_back(vector<MyCell>());
	}

	for (int i = 0; i < Rules::Settings.Days*Rules::Settings.ActivitiesPerDay; i++)
	{
		int y = week ? Rules::dayToWeekday(i / Rules::Settings.ActivitiesPerDay)*Rules::Settings.ActivitiesPerDay
			+ i % Rules::Settings.ActivitiesPerDay : i;
		
		tm time = Rules::dayToDate(i / Rules::Settings.ActivitiesPerDay);

		for (int j = 0; j < hour[i].size(); j++)
		{
			vector<int> x;
			switch (type)
			{
			case RuleData::GROUPOBJ:
				for (auto g : hour[i][j].getActivity()->getGroups())
					x.push_back(g->getId());
				break;
			case RuleData::TEACHEROBJ:
				x.push_back(hour[i][j].getActivity()->getTeacher()->getId());
				break;
			case RuleData::ACTIVITYOBJ:
				x.push_back(hour[i][j].getActivity()->getId());
				break;
			case RuleData::CLASSROOMOBJ:
				x.push_back(hour[i][j].getClassroom()->getId());
				break;
			}


			for (auto xx : x)
			{
				bool found = false;
				for (int k = 0; k<arr[y][xx].size();k++)
					if (hour[i][j].getActivity() == arr[y][xx][k].act)
					{
						arr[y][xx][k].add(hour[i][j].getClassroom(), time);
						found = true;
					}
				if (!found)
					arr[y][xx].push_back(MyCell(hour[i][j].getActivity(), hour[i][j].getClassroom(), time));
			}

		}
	}
	

	int posY = 2;
	for (int i = 0; i < n; i++)
	{

		tm time = Rules::dayToDate(i / Rules::Settings.ActivitiesPerDay);



		int maxSz = 0;
		for (int j = 0; j < names.size(); j++)
		{
			if (arr[i][j].size() > maxSz)
				maxSz = arr[i][j].size();

			for (int k = 0; k < arr[i][j].size(); k++)
			{
				string s = "...";
				switch (type)
				{
				case RuleData::GROUPOBJ:
					s = arr[i][j][k].toString(true,true,false,true,week);
					break;
				case RuleData::TEACHEROBJ:
					s = arr[i][j][k].toString(true, false, true, true, week);
					break;
				case RuleData::ACTIVITYOBJ:
					s = arr[i][j][k].toString(false, true, true, true, week);
					break;
				case RuleData::CLASSROOMOBJ:
					s = arr[i][j][k].toString(true, true, true, false, week);
					break;
				}

				sheet->Cell(posY + k, 3 + j)->SetValue(s);
				sheet->Cell(posY + k, 3 + j)->SetFormat(fmt);

				//if (week)
				//	time = arr[i][j][k].time;
			}
		}
		if (maxSz > 0)
		{

			string m1 = to_string(time.tm_mday);
			if (m1.length() == 1)
				m1 = "0" + m1;
			string m2 = to_string(time.tm_mon + 1);
			if (m2.length() == 1)
				m2 = "0" + m2;

			sheet->Cell(posY, 0)->SetValue((week ? "" : m1+"."+m2+"\n") + weekDayNames[week ? i / Rules::Settings.ActivitiesPerDay : getTmWday(time)]);
			sheet->Cell(posY, 0)->SetFormat(fmt);
			sheet->Cell(posY, 1)->SetValue(to_string(1 + i % Rules::Settings.ActivitiesPerDay));
			
			int k = Rules::Settings.ActivityStartTime[i % Rules::Settings.ActivitiesPerDay];
			m1 = to_string(k / 60);
			m2 = to_string(k % 60);

			if (m1.length() == 1)
				m1 = "0" + m1;
			if (m2.length() == 1)
				m2 = "0" + m2;

			sheet->Cell(posY, 2)->SetValue(m1+":"+m2);

		}
		posY += maxSz;
	}

	xls.SaveAs(path);
}

ostream& operator<<(ostream& os, GeneratedSchedule& generatedSchedule)
{
	
	os << generatedSchedule.hour.size() << endl;
	for (int i = 0; i < generatedSchedule.hour.size(); i++)
	{
		os << generatedSchedule.hour[i].size() << endl;
		for (int j = 0; j < generatedSchedule.hour[i].size(); j++)
		{
			os << generatedSchedule.hour[i][j];
		}
	}
	return os;
}

istream& operator>>(istream& is, GeneratedSchedule& generatedSchedule)
{
	string temp;
	getline(is, temp);
	int n = stoi(temp);
	for (int i = 0; i < n; i++)
	{
		generatedSchedule.hour.push_back(vector<FinalScheduleObject>());

		getline(is, temp);
		int m = stoi(temp);
		for (int j = 0; j < m; j++)
		{
			FinalScheduleObject obj;
			is >> obj;
			generatedSchedule.hour[i].push_back(obj);

		}
	}
	return is;
}

GeneratedSchedule Schedule;