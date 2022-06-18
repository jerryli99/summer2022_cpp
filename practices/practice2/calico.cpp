#include "calico.h"

Calico::Calico(int age, double weight, std::string name) {
	this->m_age = age;
	this->m_weight = weight;
	this->m_name = name;
}

Calico::~Calico() {}

//could improve here. Instead of using the string type, use city type etc.
void Calico::AddVisitedPlace(const string& place) {
	m_visited_places.push_back(place);
}


void Calico::PlacesTracker() {
	cout << "{";
	for (const auto& element : m_visited_places) {
		cout << "" << element << " | ";
	}
	cout << "}\n";
}

//cannot access m_favorite_toys 
