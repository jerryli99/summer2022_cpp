#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	Person();
	Person(string nickname, string country, vector<string>& languages);
	~Person();

protected:
	string m_nickname;
	string m_country;
	vector<string> m_languages;
};