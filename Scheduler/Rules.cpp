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

vector<string>& Rules::getText()
{
	return text;
}


string Rules::getErrorMessage()
{
	return errorMessage;
}

bool Rules::isEmpty()
{
	return text.empty();
}



ostream& operator<<(ostream& os, Rules& rules)
{

	vector<string> list = rules.getText();

	os << list.size() << endl;
	for (int i = 0; i < list.size(); i++)
		os << list[i] << endl;
	return os;
}

istream& operator>>(istream& is, Rules& rules)
{
	string temp;
	vector<string> list;
	int n;
	getline(is, temp);
	n = atoi(temp.c_str());
	for (int i = 0; i < n; i++)
	{
		getline(is, temp);
		list.push_back(temp);
	}

	rules.setText(list);
	return is;
}


TagRules::TagRules()
{

}

void TagRules::setText(vector<string> text)
{
	m.clear();

	for (int i = 0; i < text.size(); i++)
	{
		if (text[i].empty())
			continue;

		int z = text[i].find_first_of(' ');

		if (z == string::npos)
			continue;

		string key = text[i].substr(0,z);
		string val = text[i].substr(z+1, text[i].length() - z-1);

		if (m.find(key) == m.end())
			m.insert(std::pair<string, Rules>(key, Rules()));
		
		m[key].getText().push_back(val);
	}
}

vector<string> TagRules::getText() 
{
	vector<string> v;
	
	for (map<string, Rules>::iterator it = m.begin(); it != m.end(); ++it)
	{
		string k = it->first;
		vector<string> txt = it->second.getText();
		for (int i = 0; i < txt.size(); i++)
			v.push_back(k + " " + txt[i]);
	}


	return v;
	// TODO: вставьте здесь оператор return
}

ostream& operator<<(ostream& os, TagRules& tagRules)
{

	vector<string> list = tagRules.getText();

	os << list.size() << endl;
	for (int i = 0; i < list.size(); i++)
		os << list[i] << endl;
	return os;
}

istream& operator>>(istream& is, TagRules& tagRules)
{
	string temp;
	vector<string> list;
	int n;
	getline(is, temp);
	n = atoi(temp.c_str());
	for (int i = 0; i < n; i++)
	{
		getline(is, temp);
		list.push_back(temp);
	}
		
	tagRules.setText(list);
	return is;
}