#pragma once
#include <string>
#include <vector>
#include <array>
#include <map>
#include <ctime>
using namespace std;


int getTmWday(tm& time);

struct RulesSettings
{
public:
	tm StartDate;
	int Days;
	int ActivitiesPerDay;

	array<int,20> ActivityStartTime;
	array<int,20> ActivityEndTime;

	friend std::ostream& operator<<(std::ostream& os, RulesSettings& rules);
	friend std::istream& operator>>(std::istream& is, RulesSettings& rules);

	array<map<string, vector<int>>, 4> nameMap;
	array<int, 4> nameMapSize;
};


class RuleData
{
public:
	
	enum ruletype {FULLT, TIMET, GROUPT, TEACHERT, ACTIVITYT, CLASSROOMT, HWEEKT};

	enum objtype {GROUPOBJ, TEACHEROBJ,ACTIVITYOBJ, CLASSROOMOBJ};

	// =(0) <(1) <=(2) >(3) >=(4) 
	enum signtype {EQUAL, LESS, ELESS, GREATER,EGREATER};
	
	enum functype {UNKNOWN, NOT, AND, OR, HOUR, TIME, WEEKDAY, MONTH, DATE, GROUP, TEACHER, ACTIVITY, CLASSROOM, HPERWEEK};
	
	RuleData();
	void init();
	RuleData(string s);
	~RuleData();

	
	void and(RuleData& other);
	void or(RuleData& other);
	void not();

	bool canDayDaytime(int day, int daytime);
	bool canObj(objtype type, int id);
	int getMaxPerWeek();

private:
	static void parse(string& s, signtype& st, functype& ft, vector<string>& arg);
	bool** m;
	bool** obj;
	int maxPerWeek;
	ruletype type;
};

class Rules
{
public:

	
	static RulesSettings Settings;

	static string activityHourToStringDebug(int i);
	static string dayToStringDebug(int i);
	static int dayToWeekday(int i);
	static int dayToMonth(int i);
	static tm dayToDate(int i);
	static int dateToDay(tm date);
	Rules();
	
	
	string getErrorMessage();
	void update();
	void setText(vector<string> text);
	vector<string>&  getText();
	bool isEmpty();

	RuleData& getData();

	friend std::ostream& operator<<(std::ostream& os, Rules& rules);
	friend std::istream& operator>>(std::istream& is, Rules& rules);

private:

	vector<string> text;
	string errorMessage;
	RuleData data;
	
};


class TagRules
{
public:
	TagRules();
	void setText(vector<string> text);
	vector<string>  getText();
	void update();
	
	map<string, Rules>& getMap();
	

	vector<string> getErrorMessages();


	friend std::ostream& operator<<(std::ostream& os, TagRules& tagRules);
	friend std::istream& operator>>(std::istream& is, TagRules& tagRules);

private:
	map<string, Rules> m;
};
