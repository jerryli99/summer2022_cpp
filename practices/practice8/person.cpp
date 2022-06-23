#include "person.h"

Person::Person() {};

Person::Person(string nickname, string country, vector<string>& languages) 
	: m_nickname{ nickname }, m_country{ country }, m_languages{ languages } {};

Person::~Person() {};
