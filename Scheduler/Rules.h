#pragma once
#include "ScheduleObject.h"



class Rules
{
public:
	Rules();
	
	string getErrorMessage();
	void update();
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
