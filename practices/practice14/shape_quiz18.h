#pragma once

#include <iostream>

class Shape {
public:
	virtual std::ostream& print(std::ostream& output) const= 0;
	friend std::ostream& operator<<(std::ostream& output, const Shape& shape);
	virtual ~Shape() {};
};