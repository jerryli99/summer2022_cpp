#pragma once

#include <iostream>
#include <string>

using namespace std;

class CharacterAbility {
public:
	//I put these data members in public because I don't want to hide them.
	//Every CharacterAbility has id, name, and description
	int m_ability_id{ 0 };
	string m_ability_name{ "None" };
	string m_ability_description{ "None" };

	CharacterAbility(int ability_id, string ability_name, string ability_description);
	~CharacterAbility();
};

bool operator<(const CharacterAbility& ability1, const CharacterAbility& ability2);