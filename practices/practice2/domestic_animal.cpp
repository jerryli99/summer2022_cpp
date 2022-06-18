#include "domestic_animal.h"

DomesticAnimal::DomesticAnimal() {}

DomesticAnimal::~DomesticAnimal() {}

int DomesticAnimal::get_age() const {
	return m_age;
}

double DomesticAnimal::get_weight() const {
	return m_weight;
}

string DomesticAnimal::get_name() const {
	return m_name;
}

