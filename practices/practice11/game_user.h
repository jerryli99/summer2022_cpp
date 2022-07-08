#pragma once

#include "character.h"

#define UPDATE_POINTS_ONE 1
#define UPDATE_POINTS_TWO 2
#define UPDATE_POINTS_THREE 3
#define UPDATE_POINTS_FOUR 4

class GameUser : public Character {
public:
	GameUser(string user_name, CharacterRole role, long int user_gold);
	~GameUser();

	//override these methods from base class. 
	//health_points, level, damage will now get upgraded based on how much gold the user has.
	void UpdateHealth() override;
	void UpdateAbilityLevel(const CharacterAbility& ability) override;
	void UpdateAbilityDamage(const CharacterAbility& ability) override;

	string get_user_name() const;
	string get_user_role() const;
	long int get_user_gold() const;


private:
	string m_user_name{ "None" };
	long int m_gold_amount{ 0 };

	//change m_user_role from public to private
	using Character::m_user_role;

	int UpdatePoints();
};