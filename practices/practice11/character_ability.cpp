#include "character_ability.h"

CharacterAbility::CharacterAbility(int ability_id, string ability_name, string ability_description) 
    : m_ability_id{ ability_id}, 
      m_ability_name { ability_name }, 
      m_ability_description{ ability_description } {

    if (ability_name.length() > 15) {
        throw "Ability Name too long. Should be less than 16 characters.";
    }

    if (ability_description.length() > 60) {
        throw "Ability Description too long. Should be less than 61 characters.";
    }
};


CharacterAbility::~CharacterAbility() {};

bool operator<(const CharacterAbility& ability1, const CharacterAbility& ability2) {
    return ability1.m_ability_id < ability2.m_ability_id;
}
