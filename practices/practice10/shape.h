#pragma once
#include <iostream>
#include <string>

using namespace std;

class Shape {

 public:
	Shape(double x_position, double y_position);

	//solution
	//Shape(double x_position, double y_position, string class_name);

	~Shape();

	void MoveTo(double x_location, double y_location);
	virtual void PrintClassName();

	//solution
	string get_class_name() const; 

 protected:
	 double m_x_position{ 0.0 };
	 double m_y_position{ 0.0 };

	 //solution
	 string m_class_name{ "None" };
};