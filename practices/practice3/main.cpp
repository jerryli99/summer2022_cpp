#include "store_employee.h"
#include "store_manager.h"
#include "store_associate.h"


#include <iostream>
#include <string>

using namespace std;

int main() {
	StoreEmployee* employee1 = new StoreEmployee(123456);
	StoreManager* manager1 = new StoreManager(123445, 50000.5);
	StoreAssociate* associate1 = new StoreAssociate(443922, 35000.34);

	cout << "employee1 id: " << employee1->get_employee_id() << "\n";
	cout << "manager1 salary: " << manager1->get_manager_salary() << "\n";
	cout << "associate1 id and salary: " << associate1->get_employee_id() << ", " 
		 << associate1->get_associate_salary() << "\n";

	return 0;
}
