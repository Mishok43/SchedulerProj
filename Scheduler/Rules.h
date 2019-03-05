#pragma once
#include <string>
#include <vector>
#include <array>
#include <map>
#include <ctime>
using namespace std;


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
};

class Rules
{
public:

	
	static RulesSettings Settings;

	static string activityHourToStringDebug(int i);
	

	Rules();
	
	string getErrorMessage();
	void update(tm startDate,int dayNum);
	void setText(vector<string> text);
	vector<string>&  getText();
	bool isEmpty();

	friend std::ostream& operator<<(std::ostream& os, Rules& rules);
	friend std::istream& operator>>(std::istream& is, Rules& rules);

private:

	vector<string> text;
	string errorMessage;
	bool*** m;
};


class TagRules
{
public:
	TagRules();
	void setText(vector<string> text);
	vector<string>  getText();
	void update();
	
	Rules getRules(string key);

	vector<string> getErrorMessages();


	friend std::ostream& operator<<(std::ostream& os, TagRules& tagRules);
	friend std::istream& operator>>(std::istream& is, TagRules& tagRules);

private:
	map<string, Rules> m;
};
