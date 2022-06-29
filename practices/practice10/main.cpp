#include "shape.h"
#include "circle.h"

#include <iostream>

using namespace std;
/*
    I didn't really change much from my last example. However, I put some thinking.
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
	    Last time, the issue was:
		the Class Shape* and Shape& is not using the class Circle version of 
		PrintClassName(). We resolved it by adding a member to class Shape. 
		However, not a good idea.

		Compared to the last time of adding a member to class Shape, using the
		virtual keyword for PrintClassName() is a better way to solve the issue.

		Why use Base class pointers for Derived class anyway?
		I mean if we can just declare Circle circle1{10,1,1}, and then
		have circle1.PrintClassName(), why bother using Shape* shape1{circle1}?

		One thing I could think of is that since shape has many forms, such as shape of
		circle, shape of rectangle, and shape of triangle, we want to have a way to represent
		this concept. 

		let's say I have Circle, Rectangle, Triangle, Square, ... classes that 
		all inherits the Shape class.

		Then I could have an array of them, like
		[&circle, &rectangle, &triangle, &square, ...]

		Shape* shapes[]{&circle, &rectangle, &triangle, &square, ...}

		I want to encapsulate the features circle, rectangle, triangle, ... have, and I also want to 
		show they share a commom feature. 

		Using Shape pointers / references in this case hides its variability.
		-----------------------------------------------------------------------------------------



		--------------------------------------------------------------------------------------------
		                          Ignore This part of the comment
		--------------------------------------------------------------------------------------------
		Polymorphism of A:
		let type A {A1, A2, A3, A4, ...} where A1, A2, A3, A4, ... are all different from each other
		but share some common features which can be summerized as type A.

		type    constructors            members(public, protected, private)           functions(public, protected, private)
		A1 = {{A1(), ~A1(), ...},{[a1_10, a1_11, ..], [a1_20, ..], [a1_30, ..]...}, {[A1_func1(), ..], [A1_func2(), ..], ...}}
		A2 = {{A2(), ~A2(), ...},{[a2_10, a2_11, ..], [a2_20, ..], [a2_30, ..]...}, {[A2_func1(), ..], [A2_func2(), ..], ...}}
		A3 = {{A3(), ~A3(), ...},{[a3_10, a3_11, ..], [a3_20, ..], [a3_30, ..]...}, {[A3_func1(), ..], [A3_func2(), ..], ...}}
		...

	    Polymorphism of B: (just change a_n to b_n, An to Bn)
		let type B {B1, B2, B3, B4, ...}

		Polymorphism of C: ...
		....            D: ...
		....            E: ...


	 */
	cout << "Using the virtual keyword to override PrintClassName()\n\n";

	Shape circle_shape1{ circle };
	circle_shape1.PrintClassName();

	cout << "\n";

	Shape* circle_shape2{ &circle };
	circle_shape2->PrintClassName();

	cout << "\n";

	Shape& circle_shape3{ circle };
	circle_shape3.PrintClassName();


	return 0;
}