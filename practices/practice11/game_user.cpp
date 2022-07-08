#include "game_user.h"

GameUser::GameUser(string user_name, CharacterRole role, long int user_gold) 
	: m_user_name{ user_name }, Character{ role }, m_gold_amount{ user_gold } {};

GameUser::~GameUser() {};

void GameUser::UpdateHealth() {
	const int points = UpdatePoints();

	m_health_points += points;
	m_gold_amount -= points;

	if (m_health_points == MAX_HEALTH_POINTS) {
		cout << "Health points full.\n";
	}
}

void GameUser::UpdateAbilityLevel(const CharacterAbility& ability) {
	const int points = UpdatePoints();

	if (CheckAbilityExistence(ability)) {
		m_ability_data[ability]["ability_level"] += points;
		m_gold_amount -= points;
	}
	else {
		throw "Cannot find ability. Please use the AddAbility function.\n";
	}
}

void GameUser::UpdateAbilityDamage(const CharacterAbility& ability) {
	const int points = UpdatePoints();

	if (CheckAbilityExistence(ability)) {
		m_ability_data[ability]["ability_damage"] += (points * 10);
		m_gold_amount -= points;
	}
	else {
		throw "Cannot find ability. Please use the AddAbility function.\n";
	}
}

string GameUser::get_user_name() const {
	return m_user_name;
}

string GameUser::get_user_role() const {
	switch (m_user_role) {
		case CharacterRole::kRookie:
			return "Rookie";

		case CharacterRole::kMario:
			return "Mario";

		case CharacterRole::kAnnihilator:
			return "Annihilator";

		case CharacterRole::kPrincess:
			return "Princess";

		case CharacterRole::kBunny:
			return "Bunny";

		case CharacterRole::kHazzard:
			return "Hazzard";

		case CharacterRole::kDarkHorse:
			return "DarkHorse";

		default:
			return "None";
	}
}

long int GameUser::get_user_gold() const {
	return m_gold_amount;
}

//UpdatePoints will calculate how much points to add base on user gold amount
int GameUser::UpdatePoints() {
	if ((m_gold_amount / 100) > 1000) {
		return UPDATE_POINTS_TWO;

	} else if ((m_gold_amount / 100) > 10000) {
		return UPDATE_POINTS_THREE;

	} else if ((m_gold_amount / 100) > 100000) {
		return UPDATE_POINTS_FOUR;

	} else {
		return UPDATE_POINTS_ONE;
	}
}
