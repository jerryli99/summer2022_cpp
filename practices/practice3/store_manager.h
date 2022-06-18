#pragma once

#include "store_employee.h"

class StoreManager : public StoreEmployee {
public:
	StoreManager(double salary = 0.0, int employee_id = 0);
	~StoreManager();

	double get_manager_salary() const;

private:
	double m_salary{ 0.0 };
};