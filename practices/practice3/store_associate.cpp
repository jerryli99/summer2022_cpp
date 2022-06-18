#include "store_associate.h"

StoreAssociate::StoreAssociate(double salary, int employee_id)
	: m_salary{ salary }, StoreEmployee{ employee_id } {}

StoreAssociate::~StoreAssociate() {};

double StoreAssociate::get_associate_salary() const {
	return m_salary;
}

