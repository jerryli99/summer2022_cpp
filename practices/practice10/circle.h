#pragma once

#include "shape.h"

class Circle : public Shape {
public:
	Circle(double x_position, double y_position, double radius);

	//solution
	//Circle(double x_position, double y_position, double radius, string class_name);

	~Circle();

	//same function name in shape.h
	virtual void PrintClassName();

	double get_x_position() const;
	double get_y_position() const;
	double get_radius() const;

private:
	double m_radius{ 0.0 };
};