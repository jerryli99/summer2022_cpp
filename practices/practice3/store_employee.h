#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class StoreEmployee {
public:
	StoreEmployee(int id = 0);
	~StoreEmployee();

	int get_employee_id() const;
private:
	int m_id{ 0 };
};