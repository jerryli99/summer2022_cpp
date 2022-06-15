#include "car.h"

Car::Car() {}

Car::Car(std::string car_brand, std::string color, std::string plate_id) {
	m_car_brand = car_brand;
	m_color = color;
	m_plate_id = plate_id;
}

Car::~Car() {}


bool Car::operator==(const Car& car) {
	return (m_car_brand == car.m_car_brand &&
		    m_color == car.m_color && 
		    m_plate_id == car.m_plate_id);
}

std::ostream& operator<<(std::ostream& COUT, const Car& car)
{
	COUT << "Car brand: " << car.m_car_brand 
		 << "\nCar color: " << car.m_color 
		 << "\nCar plate_id: " << car.m_plate_id;

	return COUT;
}
