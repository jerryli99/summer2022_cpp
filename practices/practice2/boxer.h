#pragma once
#include "dog.h"

class Boxer : public Dog {
public:
	Boxer(int age, double weight, string name);
	~Boxer();
};