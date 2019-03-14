#pragma once
#include <vector>
#include <cstddef>

class UnmanagedGenerator
{
public:
	static int**** UnmanagedGenerator::generate(
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
	);

};

/*
case 0:
num = numGroups;
break;
case 2:
num = numActivities;
break;
case 3:
num = numClassrooms;
break;
*/