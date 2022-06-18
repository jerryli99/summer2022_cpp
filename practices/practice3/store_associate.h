#pragma once

#include "store_employee.h"

class StoreAssociate : public StoreEmployee {
public:
	StoreAssociate(double salary = 0.0, int employee_id = 0);
	~StoreAssociate();

	double get_associate_salary() const;

private:
	double m_salary{ 0.0 };
};