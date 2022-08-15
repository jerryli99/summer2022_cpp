#include "shape_quiz18.h"
#include "point_quiz18.h"
#include "circle_quiz18.h"
#include "triangle_quiz18.h"

#include <iostream>
#include <string>
/*
   Quiz 18. Question 2.

   2a.  Create an abstract class named Shape. This class should have three functions: 
        a pure virtual print function that takes and returns a std::ostream&, 
		an overloaded operator<<, 
		and an empty virtual destructor.
---------------------------------------------------------------------------------------------
	2b. Derive two classes from Shape: a Triangle, and a Circle. 
	    The Triangle should have 3 Points as members. 
		The Circle should have one center Point, and an integer radius. 
		Overload the print() function so the following program runs:

		int main()
		{
			Circle c{ Point{ 1, 2 }, 7 };
			std::cout << c << '\n';

			Triangle t{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }};
			std::cout << t << '\n';

			return 0;
		}

		Should print:

		Circle(Point(1, 2), radius 7)
		Triangle(Point(1, 2), Point(3, 4), Point(5, 6))

		Here is the Point class I can use:
		class Point
		{
		private:
			int m_x{};
			int m_y{};

		public:
			Point(int x, int y)
				: m_x{ x }, m_y{ y }
			{

			}

			friend std::ostream& operator<<(std::ostream& out, const Point& p)
			{
				return out << "Point(" << p.m_x << ", " << p.m_y << ')';
			}
		};
-----------------------------------------------------------------------------------------------------
	2c.  Given the above classes (Point, Shape, Circle, and Triangle), finish the following program:
	#include <vector>
	#include <iostream>

	int main()
	{
		std::vector<Shape*> v{
		  new Circle{Point{ 1, 2 }, 7},
		  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
		  new Circle{Point{ 7, 8 }, 3}
		};

		// print each shape in vector v on its own line here

		std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

		// delete each element in the vector here

		return 0;
	}

	Should print: 

	Circle(Point(1, 2), radius 7)
	Triangle(Point(1, 2), Point(3, 4), Point(5, 6))
	Circle(Point(7, 8), radius 3)
	The largest radius is: 7
--------------------------------------------------------------------------------------------------------
*/


int getLargestRadius(const std::vector<Shape*>& v_shapes) {
	int max_radius = 0;

	for (const auto& element : v_shapes) {
		auto* tmp = dynamic_cast<Circle*>(element); // if cast fails, continue iteration
		if (tmp) {
			max_radius = std::max(tmp->getRadius(), max_radius);
		}
	}
	return max_radius;
}

int main() {
	Circle c{ Point{ 1, 2 }, 7 };
	std::cout << c << '\n';

	Triangle t{ Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 } };
	std::cout << t << '\n';


	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	// print each shape in vector v on its own line here

	std::cout << "The largest radius is: " << getLargestRadius(v) << "\n\n"; // write this function

	for (const auto& element : v) {
		std::cout << "Delete: " << *element << "\n";
		delete element;
	}

	return 0;
}
