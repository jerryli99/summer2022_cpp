#pragma once

#include "shape_quiz18.h"
#include "point_quiz18.h"

#include <vector>

class Circle : public Shape {
public:
	Circle(const Point& point, int radius);
	std::ostream& print(std::ostream& output) const override;
	friend std::ostream& operator<<(std::ostream& output, const Circle& circle);

	int getRadius() const;

private:
	Point m_point;
	int m_radius;
};