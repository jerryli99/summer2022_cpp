#include "shape.h"
#include "circle.h"

#include <iostream>

using namespace std;
/*
              Shape (base class)
                   |
                   | (public inheritance)
                   |
                 circle (derived class)

*/

int main() {
	
	Circle circle{ 12, 13, 14 };
	cout << "ClassName: ";
	circle.PrintClassName();
	cout << "\n";

	cout << "circle x position:  " << circle.get_x_position() << "\n";
	cout << "circle y position:  " << circle.get_y_position() << "\n";
	cout << "circle radius:      " << circle.get_radius() << "\n\n";

	Circle& circle1{ circle };
	cout << "circle1 x position: " << circle1.get_x_position() << "\n";
	cout << "circle1 y position: " << circle1.get_y_position() << "\n";
	cout << "circle1 radius:     " << circle1.get_radius() << "\n\n";

	Circle* circle2{ &circle };
	cout << "circle2 x position: " << circle2->get_x_position() << "\n";
	cout << "circle2 y position: " << circle2->get_y_position() << "\n";
	cout << "circle2 radius:     " << circle2->get_radius() << "\n\n";


	Shape shape{ circle };
	cout << "ClassName: ";
	shape.PrintClassName();
	cout << "\n";

	Shape& shape1{ circle };
	shape1.PrintClassName();
	cout << "\n";

	Shape* shape2{ &circle };
	shape2->PrintClassName();
	cout << "\n";
	
/*
	The Shape* {circle} and Shape& {circle} above:
	It turns out shape (base class) can only see members of shape.
	Even though circle (derived class) has PrintClassName() as well, 
	the shape pointer or reference cannot see circle's PrintClassName().

	A possible way to get class name is to add a member to class Shape and
	initialize the member in the constructor. (I commented //solution in 
	class Shape and class Circle) 

	Issue:
	If I have 100 functions like PrintClassName, then I might need
	100 additional members in class Shape. Too many members and long
	constructor initialization lists to write.
*/
	cout << "------fixed-------\n";

	Circle circle3{ 10, 10, 10, "Circle"};
	cout << "ClassName: ";
	circle3.PrintClassName();
	cout << "\n";

	Shape shape3{ circle3 };
	cout << "Class name is now: " << shape3.get_class_name() << "\n";
	cout << "\n";

	Shape& shape4{ circle3 };
	cout << "Class name is now: " << shape4.get_class_name() << "\n";
	cout << "\n";

	Shape* shape5{ &circle3 };
	cout << "Class name is now: " << shape5->get_class_name() << "\n";
	cout << "\n";

	return 0;
}