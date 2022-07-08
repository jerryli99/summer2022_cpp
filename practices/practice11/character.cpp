#include "character.h"

Character::Character(CharacterRole user_role) : m_user_role{ user_role } {};

Character::~Character() {};

void Character::AddAbility(const CharacterAbility& ability, 
	                       const int ability_level, 
	                       const int ability_damage) {

	m_ability_data[ability].insert(pair<string, int>("ability_level", ability_level));
	m_ability_data[ability].insert(pair<string, int>("ability_damage", ability_damage));
}

void Character::UpdateHealth() {
	m_health_points += 1;

	if ( m_health_points == MAX_HEALTH_POINTS) {
		cout << "Health points full.\n";
	}
}

void Character::UpdateAbilityLevel(const CharacterAbility& ability) {
	if (CheckAbilityExistence(ability)) {
		m_ability_data[ability]["ability_level"] += 1;
	} else {
		throw "Cannot find ability. Please use the AddAbility function.\n";
	}
}

void Character::UpdateAbilityDamage(const CharacterAbility& ability) {
	if (CheckAbilityExistence(ability)) {
		m_ability_data[ability]["ability_damage"] += 5;
	} else {
		throw "Cannot find ability. Please use the AddAbility function.\n";
	}
}

bool Character::CheckAbilityExistence(const CharacterAbility& ability) {
	vector<CharacterAbility> ability_keys;

	for (auto i = m_ability_data.begin(); i != m_ability_data.end(); i++) {
		ability_keys.push_back(i->first);
	}

	for (const auto& key : ability_keys) {
		if (key.m_ability_id == ability.m_ability_id) {
			return true;
		}
	}

	return false;
}

void Character::ViewAbilityData() {
	vector<CharacterAbility> ability_keys;

	for (auto i = m_ability_data.begin(); i != m_ability_data.end(); i++) {
		ability_keys.push_back(i->first);
	}

	//print ability data
	cout << left
		 << setw(25) << "Ability_Name:"
		 << setw(60) << "Ability_Description:"
		 << setw(15) << "Level:"
		 << setw(15) << "Damage:"
		 << right
		 << "\n";
	
	for (const auto& key : ability_keys) {
		cout << left 
			 << setw(25) << key.m_ability_name
			 << setw(60) << key.m_ability_description
			 << setw(15) << m_ability_data[key]["ability_level"]
			 << setw(15) <<  m_ability_data[key]["ability_damage"] 
			 << right
			 << "\n";
	}
	cout << "\n\n";
}

void Character::set_jump_height(double jump_height) {
	m_jump_height = jump_height;
}

int Character::get_health_points() const {
	return m_health_points;
}

double Character::get_jump_height() const {
	return m_jump_height;
}