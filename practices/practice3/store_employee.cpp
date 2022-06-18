#include "store_employee.h"


StoreEmployee::StoreEmployee(int id) : m_id{ id } {

	//when I tried 1234567, the exception was thrown.
	if (floor(log10(id) + 1) > 6) {
		throw invalid_argument("The provided id is more than 6 digits!");
	}
}

StoreEmployee::~StoreEmployee() {}

int StoreEmployee::get_employee_id() const {
	return m_id;
}