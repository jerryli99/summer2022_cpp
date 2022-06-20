#include "automobiles.h"
#include "car.h"

#include <iostream>
#include <string>

/*
                    Automobiles
					     |
						 | (private inheritance)
						 |
				        Car


*/
int main() {
	Car* car1 = new Car("Black", "Jerry");
	car1->print_message();

	/*
	These only work when 
	class Car: public Automobiles
	
	car1->get_owner_name();
	car1->m_automobile_color;
	car1->m_automobile_name;
	*/

	return 0;
}