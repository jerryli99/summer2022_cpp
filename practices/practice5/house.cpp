#include "house.h"

House::House(double house_length, double house_width, string buyer, double land_length, double land_width)
	: m_house_length{ house_length }, 
	  m_house_width{ house_width },  
	  Land{ buyer, land_length, land_width } {};

House::~House() {};

bool House::OverSizedHouseArea() {
	
	//Use Land::get_land_area() here.
	//If I changed the name to get_area() in the Land class, and then have the 
	//same function name get_area() in the House class, it could get conflicted
	//and possibly get recursive function calls.
	if ((m_house_length * m_house_width) > Land::get_land_area()) {
		return true;
	}

	return false;
}
