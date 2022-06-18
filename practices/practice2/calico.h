#pragma once
#include "cat.h"

class Calico : public Cat {
public:
	Calico(int age, double weight, string name);
	~Calico();

	void AddVisitedPlace(const string& place);
	void PlacesTracker();
};