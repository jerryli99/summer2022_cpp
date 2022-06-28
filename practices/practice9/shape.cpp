#include "shape.h"

Shape::Shape(double x_position, double y_position) 
	: m_x_position{ x_position }, 
	  m_y_position{ y_position }{};

//solution
Shape::Shape(double x_position, double y_position, string class_name)
	: m_x_position{ x_position }, 
	  m_y_position{ y_position }, 
	  m_class_name{ class_name } {};


Shape::~Shape() {};

void Shape::MoveTo(double x_location, double y_location) {
	m_x_position = x_location;
	m_y_position = y_location;
};

void Shape::PrintClassName() {
	cout << "This is Shape\n";
}

string Shape::get_class_name() const {
	return m_class_name;
}
