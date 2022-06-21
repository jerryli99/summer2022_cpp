#include "house.h"

House::House(double house_length, double house_width, string buyer, double land_length, double land_width)
	: m_house_length{ house_length }, 
	  m_house_width{ house_width },  
	  Land{ buyer, land_length, land_width } {};

House::~House() {};

bool House::OverSizedHouseArea() {
	if ((m_house_length * m_house_width) > Land::get_land_area()) {
		return true;
	}

	return false;
}