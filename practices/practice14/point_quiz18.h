#pragma once
#include <iostream>

//This class is provided by the question.

class Point {
public:
	Point(int x, int y)
		: m_x{ x }, m_y{ y } {}

	friend std::ostream& operator<<(std::ostream& out, const Point& p);

private:
	int m_x{};
	int m_y{};
};