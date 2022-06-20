#pragma once

#include "automobiles.h"

class Car : private Automobiles {
public:
	Car(string car_color, string car_owner_name);
	~Car();

	void print_message();
};