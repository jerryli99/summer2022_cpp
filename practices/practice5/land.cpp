#include "land.h"

Land::Land(string buyer, double length, double width) 
	: m_land_buyer{ buyer }, m_land_length{ length }, m_land_width{ width } {};

Land::~Land() {};

double Land::get_land_area() const {
	return m_land_length * m_land_width;
}

/*
double Land::get_area() const {
	return m_land_length * m_land_width;
}

*/

string Land::get_land_buyer() const {
	return m_land_buyer;
}
