#include "circle.h"

Circle::Circle(double x_position, double y_position, double radius) 
	: Shape{ x_position, y_position }, m_radius{ radius } {};

//solution
Circle::Circle(double x_position, double y_position, double radius, string class_name)
	: Shape{ x_position, y_position, class_name }, m_radius{ radius } {};

Circle::~Circle() {};

void Circle::PrintClassName() {
	cout << "This is Circle\n";
}

double Circle::get_x_position() const {
	return m_x_position;
}

double Circle::get_y_position() const {
	return m_y_position;
}

double Circle::get_radius() const {
	return m_radius;
}