#include "store_manager.h"

StoreManager::StoreManager(double salary, int employee_id) 
	: m_salary{ salary }, StoreEmployee{ employee_id } {}

StoreManager::~StoreManager() {};

double StoreManager::get_manager_salary() const {
	return m_salary;
}

