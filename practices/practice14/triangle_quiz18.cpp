#include "triangle_quiz18.h"

Triangle::Triangle(const Point& point1, const Point& point2, const Point& point3)
	: m_point1{ point1 },
	  m_point2{ point2 },
	  m_point3{ point3 } {};

std::ostream& Triangle::print(std::ostream& output) const {
	return output << "Triangle(" 
		          << m_point1 << ", " 
		          << m_point2 << ", " 
		          << m_point3 << ')';
}

std::ostream& operator<<(std::ostream& output, const Triangle& triangle) {
	return output << "Triangle("
				  << triangle.m_point1 << ", "
				  << triangle.m_point2 << ", "
				  << triangle.m_point3 << ')';
}
