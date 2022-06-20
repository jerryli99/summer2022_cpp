#include "car.h"

Car::Car(string car_color, string car_owner_name) : Automobiles{ car_color, car_owner_name} {

	m_automobile_color = car_color; //can still modify public member in the Automobiles class

	m_automobile_seats = 4; //can still modify protected member in the Automobiles class

	//m_automobile_owner = "John";  cannot access private memeber

}

Car::~Car() {};

void Car::print_message() {
	cout << "Private inheritance.\n";
	cout << "Car can access protected member m_automobile_seats: " << this->m_automobile_seats << "\n";
	cout << "Car can access public function get_owner_name(): " << this->get_owner_name() << "\n";
	cout << "Car can access public member m_automobile_color: " << this->m_automobile_color << "\n";
}
