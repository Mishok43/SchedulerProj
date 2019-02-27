#include "Rules.h"



Rules::Rules()
{
	
}

void Rules::update()
{
	if (isEmpty())
		return;



}

void Rules::setText(vector<string> text)
{
	this->text = text;
}

string Rules::getErrorMessage()
{
	return errorMessage;
}

bool Rules::isEmpty()
{
	return text.empty();
}


TagRules::TagRules()
{

}