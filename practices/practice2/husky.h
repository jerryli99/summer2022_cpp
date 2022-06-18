#pragma once
#include "dog.h"

class Husky : public Dog {
public:
	Husky(int age, double weight, string name);
	~Husky();
};