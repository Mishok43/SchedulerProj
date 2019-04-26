#include "GeneratedSchedule.h"
#include <random>

#include <functional>

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
	process = new float[200];

}


void GeneratedSchedule::initRules()
{
	//Задать ID для всех объектов
	MainData.Groups.updateIds();
	MainData.Teachers.updateIds();
	MainData.Activities.updateIds();
	MainData.Classrooms.updateIds();

	//Создать мапы [ИМЯ]->[id1,id2...]

	map<string, vector<int>> groupNameMap = MainData.Groups.getNameMap();
	map<string, vector<int>> teacherNameMap = MainData.Teachers.getNameMap();
	map<string, vector<int>> activityNameMap = MainData.Activities.getNameMap();
	map<string, vector<int>> classroomNameMap = MainData.Classrooms.getNameMap();

	Rules::Settings.nameMap
		= array<map<string, vector<int>>, 4>
	{groupNameMap, teacherNameMap, activityNameMap, classroomNameMap};

	Rules::Settings.nameMapSize = array<int, 4>
	{(int)groupNameMap["Все"].size(), (int)teacherNameMap["Все"].size(), (int)activityNameMap["Все"].size(), (int)classroomNameMap["Все"].size()};

	MainData.GroupsToShow = set<string>{ "Все" };
	MainData.TeachersToShow = set<string>{ "Все" };
	MainData.ActivitiesToShow = set<string>{ "Все" };
	MainData.ClassroomsToShow = set<string>{ "Все" };

	//Обновить правила для всех объектов

	MainData.Groups.updateRules();
	MainData.Teachers.updateRules();
	MainData.Activities.updateRules();
	MainData.Classrooms.updateRules();

	//Обновить правила для всех тегов

	MainData.GroupTagRules.update();
	MainData.TeacherTagRules.update();
	MainData.ActivityTagRules.update();
	MainData.ClassroomTagRules.update();

	//Добавить к правилам для объектов правила для тегов

	MainData.Groups.uniteWithTagRules(MainData.GroupTagRules);
	MainData.Teachers.uniteWithTagRules(MainData.TeacherTagRules);
	MainData.Activities.uniteWithTagRules(MainData.ActivityTagRules);
	MainData.Classrooms.uniteWithTagRules(MainData.ClassroomTagRules);


	//Добавить к правилам для занятий правила соотв. преподов и групп

	vector<Activity*> activities = MainData.Activities.getVal();
	for (auto activity : activities)
	{
		if (activity->getTeacher()->getRules().getErrorMessage().empty())
			activity->getRules().getData().and(activity->getTeacher()->getRules().getData());

		for (auto group : activity->getGroups())
			if (group->getRules().getErrorMessage().empty())
				activity->getRules().getData().and(group->getRules().getData());
	}



}

vector<pair<string, string>> GeneratedSchedule::getErrors()
{
	vector<pair<string, string>> v;
	
	
	for (auto o : MainData.Groups.getErrors("Группы"))
		v.push_back(o);
	for (auto o : MainData.Teachers.getErrors("Преподаватели"))
		v.push_back(o);
	for (auto o : MainData.Activities.getErrors("Дисциплины"))
		v.push_back(o);
	for (auto o : MainData.Classrooms.getErrors("Аудитории"))
		v.push_back(o);

	for (auto o : MainData.GroupTagRules.getErrors("Теги групп"))
		v.push_back(o);
	for (auto o : MainData.TeacherTagRules.getErrors("Теги преподавателей"))
		v.push_back(o);
	for (auto o : MainData.ActivityTagRules.getErrors("Теги дисциплин"))
		v.push_back(o);
	for (auto o : MainData.ClassroomTagRules.getErrors("Теги аудиторий"))
		v.push_back(o);

	return v;
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

	bool simple = false;
	if (!simple)
	{

		reset();

		vector<Activity*> act = MainData.Activities.getVal();

		vector<Classroom*> cls = MainData.Classrooms.getVal();
		int n = Rules::Settings.Days * Rules::Settings.ActivitiesPerDay;
		for (int i = 0; i < n; i++)
		{
			hour.push_back(vector<FinalScheduleObject>());
		}

		std::function<bool(vector<vector<FinalScheduleObject>>&, int, int, Activity*, Classroom*)> put = [n](vector<vector<FinalScheduleObject>>& hour, int dayTime, int hourTime, Activity* act, Classroom* cl)
		{
			int k = 0;
			while (Rules::dayToWeekday(k / Rules::Settings.ActivitiesPerDay) != dayTime)
				k++;

			k += hourTime;

			for (int i = 0; i < act->getHours(); i++)
			{
				hour[k + i * 7 * Rules::Settings.ActivitiesPerDay].push_back(FinalScheduleObject(act, cl));
			}

			return true;
		};

		std::function<bool(vector<vector<FinalScheduleObject>>&, int, int, Activity*)> unput = [n](vector<vector<FinalScheduleObject>>& hour, int dayTime, int hourTime, Activity* act)
		{
			int k = 0;
			while (Rules::dayToWeekday(k / Rules::Settings.ActivitiesPerDay) != dayTime)
				k++;

			k += hourTime;

			for (int i = 0; i < act->getHours(); i++)
			{
				hour[k + i * 7 * Rules::Settings.ActivitiesPerDay].pop_back();
			}

			return true;
		};




		std::function<void(int)> finder = [this,&finder,&put,&unput,n,&act,&cls]( int i)
		{

			if (i == act.size())
			{
				updateSolutions();
				return;
			}


			int sum = 0;
			//bool donee = false;


			for (auto g : act[i]->getGroups())
				sum += g->getSize();

			for (int dayTime = 0; dayTime < 7; dayTime++)
				for (int hourTime = 0; hourTime < Rules::Settings.ActivitiesPerDay; hourTime++)
					if (act[i]->getRules().getData().canDayDaytime(dayTime, hourTime))
					{
						

						int r = dayTime * Rules::Settings.ActivitiesPerDay + hourTime;

						
						bool used = false;

						for (auto h : hour[r])
						{
							if (h.getActivity()->getTeacher() == act[i]->getTeacher())
								used = true;

							for (auto g1 : h.getActivity()->getGroups())
								for (auto g2 : act[i]->getGroups())
									if (g1 == g2)
										used = true;
						}

						if (used)
							continue;

						for (int k = 0; k < cls.size(); k++)
							if (sum <= cls[k]->getCapacity()
								&& act[i]->getRules().getData().canObj(RuleData::CLASSROOMOBJ, cls[k]->getId())
								&& cls[k]->getRules().getData().canObj(RuleData::ACTIVITYOBJ, act[i]->getId()))
							{
								process[i] = (r*k) * 1.0 / (7 * Rules::Settings.ActivitiesPerDay*cls.size());

								used = false;
								for (auto h : hour[r])
								{
									if (h.getClassroom() == cls[k])
										used = true;

								}

								if (used)
									continue;

								put(hour, dayTime, hourTime, act[i], cls[k]);

								finder( i + 1);

								unput(hour, dayTime, hourTime, act[i]);
								
							}

					}



			for (int z = 0; z < act[i]->getHours(); z++)
			{
				//bool done = false;
				for (int dayTime = 0; dayTime < Rules::Settings.Days ; dayTime++)
					for (int hourTime = 0; hourTime < Rules::Settings.ActivitiesPerDay; hourTime++)
						if (act[i]->getRules().getData().canDayDaytime(dayTime, hourTime))
						{
							int r = dayTime * Rules::Settings.ActivitiesPerDay + hourTime;



							bool used = false;

							for (auto h : hour[r])
							{
								if (h.getActivity()->getTeacher() == act[i]->getTeacher())
									used = true;

								for (auto g1 : h.getActivity()->getGroups())
									for (auto g2 : act[i]->getGroups())
										if (g1 == g2)
											used = true;
							}

							if (used)
								continue;

							for (int k = 0; k < cls.size(); k++)
								if (sum <= cls[k]->getCapacity()
									&& act[i]->getRules().getData().canObj(RuleData::CLASSROOMOBJ, cls[k]->getId())
									&& cls[k]->getRules().getData().canObj(RuleData::ACTIVITYOBJ, act[i]->getId()))
								{
									used = false;
									for (auto h : hour[r])
									{
										if (h.getClassroom() == cls[k])
											used = true;

									}

									if (used)
										continue;

									hour[r].push_back(FinalScheduleObject(act[i], cls[k]));

									finder(i + 1);

									hour[r].pop_back();
								}

						}
			}


		};


		finder(0);

		//process = 1000;
		/*
		std::vector<std::pair<bool**, bool**>> activities(MainData.Activities.getVal().size());
		std::vector<uint32_t> maxPerWeekActivities(MainData.Activities.getVal().size());
		for (std::size_t i = 0; i < MainData.Activities.getVal().size(); ++i)
		{
			auto val = MainData.Activities.getVal();


			activities[i] = std::make_pair(
				val[i]->getRules().getData().getObjData(),
				val[i]->getRules().getData().getMData()
			);
			maxPerWeekActivities[i] = val[i]->getRules().getData().getMaxPerWeek();
		}

		std::vector<std::pair<bool**, bool**>> classrooms(MainData.Classrooms.getVal().size());
		std::vector<uint32_t> maxPerWeekClassrooms(MainData.Classrooms.getVal().size());
		for (std::size_t i = 0; i < MainData.Classrooms.getVal().size(); ++i)
		{
			auto val = MainData.Classrooms.getVal();


			classrooms[i] = std::make_pair(
				val[i]->getRules().getData().getObjData(),
				val[i]->getRules().getData().getMData()
			);
			maxPerWeekClassrooms[i] = val[i]->getRules().getData().getMaxPerWeek();
		}

		std::vector<std::pair<bool**, bool**>> groups(MainData.Groups.getVal().size());
		std::vector<uint32_t> maxPerWeekGroups(MainData.Groups.getVal().size());
		for (std::size_t i = 0; i < MainData.Groups.getVal().size(); ++i)
		{
			auto val = MainData.Groups.getVal();


			groups[i] = std::make_pair(
				val[i]->getRules().getData().getObjData(),
				val[i]->getRules().getData().getMData()
			);
			maxPerWeekGroups[i] = val[i]->getRules().getData().getMaxPerWeek();
		}

		std::vector<uint32_t> numHoursPerActivitity(MainData.Activities.Count());
		for (std::size_t i = 0; i < numHoursPerActivitity.size(); ++i)
		{
			numHoursPerActivitity[i] = MainData.Activities.getByPos(i)->getHours();
		}

		int**** res = UnmanagedGenerator::generate(
			Rules::Settings.Days,
			Rules::Settings.ActivitiesPerDay,
			MainData.Groups.getVal().size(),
			MainData.Activities.getVal().size(),
			MainData.Classrooms.getVal().size(),
			activities,
			classrooms,
			groups,
			maxPerWeekActivities,
			maxPerWeekClassrooms,
			maxPerWeekGroups,
			numHoursPerActivitity
		);
		assert(res != nullptr);

	
		reset();

		vector<Activity*> act = MainData.Activities.getVal();

		vector<Classroom*> cls = MainData.Classrooms.getVal();
		int n = Rules::Settings.Days * Rules::Settings.ActivitiesPerDay;

		for (int i = 0; i < n; i++)
		{
			hour.push_back(vector<FinalScheduleObject>());
		}

		for (std::size_t d = 0, ah = 0; d < Rules::Settings.Days; ++d)
		{
			for (std::size_t h = 0; h < Rules::Settings.ActivitiesPerDay; ++h, ++ah)
			{
				for (std::size_t g = 0; g < MainData.Groups.getVal().size(); ++g)
				{
					for (std::size_t a = 0; a < MainData.Activities.getVal().size(); ++a)
					{
						if (res[g][d][h][a] != -1)
						{
							FinalScheduleObject f = FinalScheduleObject(act[a], cls[res[g][d][h][a]]);
							bool can = true;
							for (std::size_t k = 0; k < hour[ah].size(); ++k)
							{
								if (hour[ah][k].getActivity() == act[a] || hour[ah][k].getClassroom() == cls[res[g][d][h][a]])
								{
									can = false;
									break;
								}

							}
							if (can)
								hour[ah].push_back(f);
						}

					}
				}
			}
		}*/
	}
	else
	{


		reset();

		vector<Activity*> act = MainData.Activities.getVal();

		vector<Classroom*> cls = MainData.Classrooms.getVal();
		int n = Rules::Settings.Days * Rules::Settings.ActivitiesPerDay;
		for (int i = 0; i < n; i++)
		{
			hour.push_back(vector<FinalScheduleObject>());
		}

		std::function<bool(vector<vector<FinalScheduleObject>>&, int, int, Activity*, Classroom*)> put = [n](vector<vector<FinalScheduleObject>>& hour, int dayTime, int hourTime, Activity* act, Classroom* cl)
		{


			int k = 0;
			while (Rules::dayToWeekday(k / Rules::Settings.ActivitiesPerDay) != dayTime)
				k++;

			k += hourTime;



			for (int i = 0; i < act->getHours(); i++)
			{
				hour[k + i * 7 * Rules::Settings.ActivitiesPerDay].push_back(FinalScheduleObject(act, cl));
			}

			return true;
		};


		vector<bool> donee;

		for (int i = 0; i < act.size(); i++)
		{
			donee.push_back(false);

			int sum = 0;
			for (auto g : act[i]->getGroups())
				sum += g->getSize();

			for (int dayTime = 0; dayTime < 7 && !donee[i]; dayTime++)
				for (int hourTime = 0; hourTime < Rules::Settings.ActivitiesPerDay && !donee[i]; hourTime++)
					if (act[i]->getRules().getData().canDayDaytime(dayTime, hourTime))
					{
						int r = dayTime * Rules::Settings.ActivitiesPerDay + hourTime;



						bool used = false;

						for (auto h : hour[r])
						{
							if (h.getActivity()->getTeacher() == act[i]->getTeacher())
								used = true;

							for (auto g1 : h.getActivity()->getGroups())
								for (auto g2 : act[i]->getGroups())
									if (g1 == g2)
										used = true;
						}

						if (used)
							continue;

						for (int k = 0; k < cls.size() && !donee[i]; k++)
							if (sum <= cls[k]->getCapacity()
								&& act[i]->getRules().getData().canObj(RuleData::CLASSROOMOBJ, cls[k]->getId())
								&& cls[k]->getRules().getData().canObj(RuleData::ACTIVITYOBJ, act[i]->getId()))
							{
								used = false;
								for (auto h : hour[r])
								{
									if (h.getClassroom() == cls[k])
										used = true;

								}

								if (used)
									continue;

								put(hour, dayTime, hourTime, act[i], cls[k]);
								donee[i] = true;
							}

					}
		}



		for (int i = 0; i < act.size(); i++)
			if (!donee[i])
			{
				int sum = 0;
				for (auto g : act[i]->getGroups())
					sum += g->getSize();

				for (int z = 0; z < act[i]->getHours(); z++)
				{
					bool done = false;
					for (int dayTime = 0; dayTime < Rules::Settings.Days && !done; dayTime++)
						for (int hourTime = 0; hourTime < Rules::Settings.ActivitiesPerDay && !done; hourTime++)
							if (act[i]->getRules().getData().canDayDaytime(dayTime, hourTime))
							{
								int r = dayTime * Rules::Settings.ActivitiesPerDay + hourTime;



								bool used = false;

								for (auto h : hour[r])
								{
									if (h.getActivity()->getTeacher() == act[i]->getTeacher())
										used = true;

									for (auto g1 : h.getActivity()->getGroups())
										for (auto g2 : act[i]->getGroups())
											if (g1 == g2)
												used = true;
								}

								if (used)
									continue;

								for (int k = 0; k < cls.size() && !done; k++)
									if (sum <= cls[k]->getCapacity()
										&& act[i]->getRules().getData().canObj(RuleData::CLASSROOMOBJ, cls[k]->getId())
										&& cls[k]->getRules().getData().canObj(RuleData::ACTIVITYOBJ, act[i]->getId()))
									{
										used = false;
										for (auto h : hour[r])
										{
											if (h.getClassroom() == cls[k])
												used = true;

										}

										if (used)
											continue;

										hour[r].push_back(FinalScheduleObject(act[i], cls[k]));

										done = true;
									}

							}
				}
			}


	}

/*
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

	}*/
}


void GeneratedSchedule::updateSolutions()
{
	solutionsFound++;
	solutions.clear();
	solutions.push_back({ hour,{-1,-1,-1} });
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
		sheet->Cell(1 + j, 0)->SetValue(to_string(j + 1));
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
		case RuleData::GROUPOBJ:
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
	sheet->SetColWidth(0, 14 * 300);
	sheet->Cell(0, 0)->SetValue(MainData.Title);
	sheet->Cell(1, 0)->SetValue(week ? "День" : "Дата/День");
	sheet->Cell(1, 1)->SetValue("Пара");
	sheet->Cell(1, 2)->SetValue("Время");

	for (int i = 0; i < names.size(); i++)
	{
		sheet->Cell(1, i + 3)->SetValue(names[i]);
		sheet->SetColWidth(i + 3, 21 * 300);
	}


	struct MyCell
	{
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
				s += act->getGroupsAsString() + (classroom || (date && !classroom) ? "\n" : "");

			bool mustAddLine = false;



			for (map<Classroom*, vector<tm>>::iterator it = cl.begin(); it != cl.end(); ++it)
			{

				if (mustAddLine)
					s += "\n";
				mustAddLine = true;
				if (classroom)
				{
					s += it->first->getName();
				}
				if (date)
				{
					if (classroom) s += ": ";
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
		map<Classroom*, vector<tm>> cl;
		tm time;

	};

	int n = week ? 7 * Rules::Settings.ActivitiesPerDay : Rules::Settings.Days*Rules::Settings.ActivitiesPerDay;

	vector<string> weekDayNames = vector<string>{ "Понедельник", "Вторник", "Среда","Четверг","Пятница","Суббота","Воскресенье" };



	vector<vector<bool>> showObj;

	for (int i = 0; i < 4; i++)
		showObj.push_back(vector<bool>());
	
	for (auto k : MainData.Groups.getVal())
		showObj[0].push_back(false);
	for (auto k : MainData.Teachers.getVal())
		showObj[1].push_back(false);
	for (auto k : MainData.Activities.getVal())
		showObj[2].push_back(false);
	for (auto k : MainData.Classrooms.getVal())
		showObj[3].push_back(false);


	for (auto s : GlobalData::GroupsToShow)
		for (auto o : Rules::Settings.nameMap[0][s])
			showObj[0][MainData.Groups.getByPos(o)->getId()] = true;

	for (auto s : GlobalData::TeachersToShow)
		for (auto o : Rules::Settings.nameMap[1][s])
			showObj[1][MainData.Teachers.getByPos(o)->getId()] = true;

	for (auto s : GlobalData::ActivitiesToShow)
		for (auto o : Rules::Settings.nameMap[2][s])
			showObj[2][MainData.Activities.getByPos(o)->getId()] = true;

	for (auto s : GlobalData::ClassroomsToShow)
		for (auto o : Rules::Settings.nameMap[3][s])
			showObj[3][MainData.Classrooms.getByPos(o)->getId()] = true;

	vector<vector<vector<MyCell>>> arr;

	for (int i = 0; i < n; i++)
	{
		arr.push_back(vector<vector<MyCell>>());
		for (int j = 0; j < names.size(); j++)
			arr[i].push_back(vector<MyCell>());
	}

	for (int i = 0; i < Rules::Settings.Days*Rules::Settings.ActivitiesPerDay; i++)
		if ((i / Rules::Settings.ActivitiesPerDay >= startDay) && (i / Rules::Settings.ActivitiesPerDay <= endDay))
		{
			int y = week ? Rules::dayToWeekday(i / Rules::Settings.ActivitiesPerDay)*Rules::Settings.ActivitiesPerDay
				+ i % Rules::Settings.ActivitiesPerDay : i;

			tm time = Rules::dayToDate(i / Rules::Settings.ActivitiesPerDay);

			for (int j = 0; j < hour[i].size(); j++)
			{
				
				bool show = true;

				for (auto g : hour[i][j].getActivity()->getGroups())
					if (!showObj[0][g->getId()])
						show = false;
				
				if (!showObj[1][hour[i][j].getActivity()->getTeacher()->getId()]
					|| !showObj[2][hour[i][j].getActivity()->getId()]
					|| !showObj[3][hour[i][j].getClassroom()->getId()])
					show = false;

				if (!show)
					continue;

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
					for (int k = 0; k<arr[y][xx].size(); k++)
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
						s = arr[i][j][k].toString(true, true, false, true, week);
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

			sheet->Cell(posY, 0)->SetValue((week ? "" : m1 + "." + m2 + "\n") + weekDayNames[week ? i / Rules::Settings.ActivitiesPerDay : getTmWday(time)]);
			sheet->Cell(posY, 0)->SetFormat(fmt);
			sheet->Cell(posY, 1)->SetValue(to_string(1 + i % Rules::Settings.ActivitiesPerDay));

			int k = Rules::Settings.ActivityStartTime[i % Rules::Settings.ActivitiesPerDay];
			m1 = to_string(k / 60);
			m2 = to_string(k % 60);

			if (m1.length() == 1)
				m1 = "0" + m1;
			if (m2.length() == 1)
				m2 = "0" + m2;

			sheet->Cell(posY, 2)->SetValue(m1 + ":" + m2);

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
	generatedSchedule.hour.clear();

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


	if (n != 0)
		generatedSchedule.initRules();

	return is;
}

GeneratedSchedule Schedule;