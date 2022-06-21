#pragma once

#include "land.h";

class House : public Land {
public:
	House(double house_length, double house_width, string buyer, 
		double land_length, double land_width);

	~House();

	double m_house_length{ 0.0 };
	double m_house_width{ 0.0 };

	bool OverSizedHouseArea();
	//double get_area() const;

	//could make house_length, house_width private.
	// add setter & getter in public.
};
