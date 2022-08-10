#include "circle_quiz18.h"

Circle::Circle(const Point& point, int radius)
	: m_point{ point },
      m_radius{ radius } {};

std::ostream& Circle::print(std::ostream& output) const {
	return output << "Circle(" 
		          << m_point << ", radius " 
		          << m_radius << ')';
}

std::ostream& operator<<(std::ostream& output, const Circle& circle) {
	return output << "Circle("
				  << circle.m_point << ", radius "
				  << circle.m_radius << ')';
}
int Circle::getRadius() const {
	return m_radius;
}
