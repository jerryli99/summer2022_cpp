#pragma once
#include "domestic_animal.h"

#include <iostream>

class Dog : public DomesticAnimal {
public:
	Dog();
	~Dog();
	void DogSound();

};
