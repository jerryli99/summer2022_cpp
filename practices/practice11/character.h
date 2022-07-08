#pragma once

#include "character_ability.h"

#include <vector>
#include <map>
#include <iomanip>

#define MAX_HEALTH_POINTS 10000

/*
ability_data map structure:
        
		  key1                             value1

CharacterAbility *ability1 -> [      key2             value2
                               ability_level,         number
                               ability_damage,        number
							  ]


CharacterAbility *ability2 -> [      key2             value2
							   ability_level,         number
							   ability_damage,        number
							  ]

	 ...                            ...                ...

CharacterAbility *abilityn -> [      key2             value2
							   ability_level,         number
							   ability_damage,        number
							  ]

*/

class Character {
public:
	/*
		These are just random game role names.
		I use enum class here to organize what roles are in the game.
		The naming with k as prefix here is from Google's C++ style guide.
		https://google.github.io/styleguide/cppguide.html#Enumerator_Names
	*/
	enum class CharacterRole : short{
		kNone = 0,
		kRookie,
		kMario,
		kAnnihilator,
		kPrincess,
		kBunny,
		kHazzard,
		kDarkHorse
	};
	CharacterRole m_user_role{ CharacterRole::kNone };

	Character(CharacterRole user_role);
	~Character();

	void AddAbility(const CharacterAbility& ability, 
		            const int ability_level, 
		            const int ability_damage);
	
	virtual void UpdateHealth();
	virtual void UpdateAbilityLevel(const CharacterAbility& ability);
	virtual void UpdateAbilityDamage(const CharacterAbility& ability);
	
	bool CheckAbilityExistence(const CharacterAbility& ability);
	void ViewAbilityData();

	void set_jump_height(double jump_height);

	int get_health_points() const;
	double get_jump_height() const;

protected:
	//composition. Every character must have their own ability when they are created.
	map<CharacterAbility, map<string, long int>> m_ability_data{};
	int m_health_points{ 0 };

private:
	double m_jump_height{ 0 };
};
