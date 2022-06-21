#pragma once

#include <iostream>
#include <string>

using namespace std;

//base class
class Land {
public:
	Land(string buyer, double length, double width);
	~Land();

	double get_land_area() const;
	//double get_area() const;
	string get_land_buyer() const;

	//could have more functions, like price, loan functions added later

protected:
	double m_land_length{ 0.0 };
	double m_land_width{ 0.0 };


private:
	string m_land_buyer{ "None" };
};
