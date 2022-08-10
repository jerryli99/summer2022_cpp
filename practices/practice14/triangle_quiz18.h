#pragma once

#include "shape_quiz18.h"
#include "point_quiz18.h"

class Triangle : public Shape {
public:
	Triangle(const Point& point1, const Point& point2, const Point& point3);
	std::ostream& print(std::ostream& output) const override;
	friend std::ostream& operator<<(std::ostream& output, const Triangle& triangle);

private:
	Point m_point1;
	Point m_point2;
	Point m_point3;
};