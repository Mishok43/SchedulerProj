#pragma once
#include "ScheduleObject.h"



class Rules
{
public:
	Rules();
	
	string getErrorMessage();
	void update();
	void setText(vector<string> text);
	bool isEmpty();
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
	void update();
	
	Rules getRules(string key);

	vector<string> getErrorMessages();


private:
	map<string, Rules> m;
};
