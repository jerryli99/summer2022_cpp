#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string.h>

class Car {
 public:
	Car();
	Car(std::string car_brand, std::string color, std::string plate_id);
	~Car();

	bool operator==(const Car& car);
	friend std::ostream& operator<<(std::ostream& COUT, const Car& car);

 private:
	std::string m_car_brand;
	std::string m_color;
	std::string m_plate_id;
};
#endif
