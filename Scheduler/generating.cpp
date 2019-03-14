#include "generating.h"
#include "ortools/sat/cp_model.h"

using namespace operations_research;
using namespace sat;

BoolVar***** data;

int**** UnmanagedGenerator::generate(
	std::size_t numDays,
	std::size_t numActivitiesPerDay,
	std::size_t numGroups,
	std::size_t numActivities,
	std::size_t numClassrooms,
	const std::vector<std::pair<bool**, bool**>>& activities,
	const std::vector<std::pair<bool**, bool**>>& classrooms,
	const std::vector<std::pair<bool**, bool**>>& groups,
	const std::vector<uint32_t>& maxPerWeekActivities,
	const std::vector<uint32_t>& maxPerWeekClassrooms,
	const std::vector<uint32_t>& maxPerWeekGroups,
	const std::vector<uint32_t>& numHoursPerActivity
)
{
	CpModelBuilder cp_model;

	data = new BoolVar****[numGroups];
	for (std::size_t i = 0; i < numGroups; ++i)
	{
		data[i] = new BoolVar***[numDays];
		for (std::size_t j = 0; j < numDays; ++j)
		{
			data[i][j] = new BoolVar**[numActivitiesPerDay];
			for (std::size_t k = 0; k < numActivitiesPerDay; ++k)
			{
				data[i][j][k] = new BoolVar*[numActivities];
				for (std::size_t m = 0; m < numActivities; ++m)
				{
					data[i][j][k][m] = new BoolVar[numClassrooms];
					for (std::size_t r = 0; r < numClassrooms; ++r)
					{
						data[i][j][k][m][r] = cp_model.NewBoolVar();
					}
				}
			}
		}
	}

	for (char typ = 0; typ < 4; ++typ)
	{

		if (typ == 1)
			continue;

		const std::vector<std::pair<bool**, bool**>>* ruleData;
		const std::vector<uint32_t>* maxData;
		uint32_t numData;

		switch (typ)
		{
			case 0:
				{
					ruleData = &groups;
					maxData = &maxPerWeekGroups;
					numData = numGroups;
					break;
				}
			case 2:
				{
					ruleData = &activities;
					maxData = &maxPerWeekActivities;
					numData = numActivities;
					break;
				}
			case 3:
				{
					ruleData = &classrooms;
					maxData = &maxPerWeekClassrooms;
					numData = numClassrooms;
					break;
				}
		}

		for (std::size_t i = 0; i < numData; ++i)
		{


			bool** objData = (*ruleData)[i].first;
			bool** mData = (*ruleData)[i].second;
			uint32_t maxPeerWeek = (*maxData)[i];

			std::vector<std::vector<BoolVar>> inWeeks;
			std::vector<BoolVar> vars;

			std::vector<BoolVar> curWeek;
			for (std::size_t g = 0; g < numGroups; ++g)
			{
				bool gBlock = !objData[0][g];
				if (typ == 0 && g == i)
					gBlock = false;
				for (std::size_t d = 0; d < numDays; ++d)
				{
					if (d % 7 == 0)
					{
						inWeeks.push_back(curWeek);
						curWeek.clear();
					}

					for (std::size_t h = 0; h < numActivitiesPerDay; ++h)
					{
						bool dhBlock = !mData[d][h];

						for (std::size_t a = 0; a < numActivities; ++a)
						{
							bool aBlock = !objData[2][a];
							if (typ == 2 && a == i)
								aBlock = false;
							for (std::size_t c = 0; c < numClassrooms; ++c)
							{
								bool cBlock = !objData[3][c];
								if (typ == 3 && c == i)
									cBlock = false;
								if (aBlock || cBlock || dhBlock || gBlock)
								{
									vars.push_back(data[g][d][h][a][c].Not());
								}
								curWeek.push_back(data[g][d][h][a][c]);
							}
						}
					}
				}
			}

			for (std::size_t j = 0; j < inWeeks.size(); ++j)
			{
				LinearExpr l0 = LinearExpr::BooleanSum(inWeeks[i]);
				LinearExpr l1 = LinearExpr(maxPeerWeek);
				cp_model.AddLessOrEqual(l0, l1);
			}
		}
	}


	for (std::size_t a = 0; a < numActivities; ++a)
	{

		for (std::size_t g = 0; g < numGroups; ++g)
		{
			std::vector<BoolVar> curActivity;

			for (std::size_t d = 0; d < numDays; ++d)
			{
				for (std::size_t h = 0; h < numActivitiesPerDay; ++h)
				{
					for (std::size_t c = 0; c < numClassrooms; ++c)
					{
						curActivity.push_back(data[g][d][h][a][c]);

					}
				}


			}

			LinearExpr l0 = LinearExpr::BooleanSum(curActivity);
			LinearExpr l1 = LinearExpr(std::max(numHoursPerActivity[a] / 3, 1u));
			cp_model.AddEquality(l0, l1);
		}
	}

	Model model;
	SatParameters satParams;
	satParams.set_max_time_in_seconds(60 * 5.0);
	//model.Add(NewSatParameters(satParams));
	const CpSolverResponse response = SolveWithModel(cp_model, &model);

	std::cout << CpSolverResponseStats(response);

	if (response.status() == CpSolverStatus::FEASIBLE)
	{
		int**** bData = new int***[numGroups];
		for (std::size_t i = 0; i < numGroups; ++i)
		{
			bData[i] = new int**[numDays];
			for (std::size_t j = 0; j < numDays; ++j)
			{
				bData[i][j] = new int*[numActivitiesPerDay];
				for (std::size_t k = 0; k < numActivitiesPerDay; ++k)
				{
					bData[i][j][k] = new int[numActivities];
					for (std::size_t m = 0; m < numActivities; ++m)
					{
						bData[i][j][k][m] = -1;
						for (std::size_t r = 0; r < numClassrooms; ++r)
						{
							if (SolutionBooleanValue(response, data[i][j][k][m][r]))
							{
								bData[i][j][k][m] = r;
							}
						}
					}
				}
			}
		}
		delete[] data;
		return bData;
	}

	delete[] data;
	return nullptr;

	/*	std::size_t numNurses = 4;
	std::size_t numShifts = 3;
	std::size_t numDays = 3;
	for (std::size_t i = 0; i < numNurses; ++i)
	{
	shifts[i] = new BoolVar*[numDays];
	for (std::size_t j = 0; j < numDays; ++j)
	{
	shifts[i][j] = new BoolVar[numShifts];
	for (std::size_t k = 0; k < numShifts; ++k)
	{
	shifts[i][j][k] = cp_model.NewBoolVar();
	}
	}
	}


	for (std::size_t i = 0; i < numDays; ++i)
	{
	for (std::size_t j = 0; j < numShifts; ++j)
	{
	std::vector<BoolVar> nursesShifts(numNurses);
	for (std::size_t k = 0; k < numNurses; ++k)
	{
	nursesShifts[k] = shifts[k][i][j];
	}

	cp_model.AddBoolOr(nursesShifts);
	}
	}

	for (std::size_t i = 0; i < numDays; ++i)
	{
	for (std::size_t j = 0; j < numNurses; ++j)
	{
	std::vector<BoolVar> shiftsByNurse(numShifts);
	for (std::size_t k = 0; k < numShifts; ++k)
	{
	shiftsByNurse[k] = shifts[j][i][k];
	}
	LinearExpr le0 = LinearExpr::BooleanSum(shiftsByNurse);
	LinearExpr le1 = LinearExpr(1);
	cp_model.AddLessOrEqual(le0, le1);
	}
	}

	for (std::size_t j = 0; j < numNurses; ++j)
	{
	std::vector<BoolVar> allShiftsByNurse(numShifts*numDays);
	for (std::size_t k = 0, d = 0; k < numDays; ++k)
	{
	for (std::size_t i = 0; i < numShifts; ++i, ++d)
	{
	allShiftsByNurse[d] = shifts[j][k][i];
	}
	}

	int32_t minWorkDaysForNurse = (numShifts*numDays) / numNurses;
	int32_t maxWorkDaysForNurse = minWorkDaysForNurse + 1;

	LinearExpr le0 = LinearExpr::BooleanSum(allShiftsByNurse);
	LinearExpr le1 = LinearExpr(minWorkDaysForNurse);
	LinearExpr le2 = LinearExpr(maxWorkDaysForNurse);
	cp_model.AddGreaterOrEqual(le0, le1);
	cp_model.AddLessOrEqual(le0, le2);
	}



	Model model;
	SatParameters params;
	params.set_max_time_in_seconds(10.0);
	model.Add(NewSatParameters(params));

	const CpSolverResponse response = SolveWithModel(cp_model, &model);

	std::cout << CpSolverResponseStats(response);

	if (response.status() == CpSolverStatus::FEASIBLE)
	{
	for (std::size_t i = 0; i < numNurses; ++i)
	{
	for (std::size_t j = 0; j < numDays; ++j)
	{
	for (std::size_t k = 0; k < numShifts; ++k)
	{
	if (SolutionBooleanValue(response, shifts[i][j][k]))
	{
	std::cout << "Nurse " << i << " work in day: " << j << " in shift: " << k << std::endl;
	}
	}
	}
	}
	}*/



}