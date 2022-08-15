#pragma warning( disable : 4250 )

#include <iostream>

//Virtual base clases 18.8 and Object slicing 18.9

class Base {
public:
	Base() { std::cout << "This is Base.\n"; };
	Base(const Base&) { std::cout << "Copy constructor from Base.\n"; };
	virtual void function1() { std::cout << "function1() from Base.\n"; };
	virtual void function2() { std::cout << "function2() from Base.\n"; };
	virtual void function3() { std::cout << "function3() from Base.\n"; };
};

class Derive1 : virtual public Base {
public:
	Derive1() { std::cout << "This is Derive1.\n"; };
	Derive1(const Derive1&) { std::cout << "Copy constructor from Derive1.\n"; };
	void function1() override { std::cout << "function1() from Derive1.\n"; };
};

class Derive2 : virtual public Base {
public:
	Derive2() { std::cout << "This is Derive2.\n"; };
	void function2() override { std::cout << "function2() from Derive2.\n"; };
};

class DeriveClasses : public Derive1, public Derive2 {
public:
	DeriveClasses() { std::cout << "This is DeriveClasses.\n"; };
	void function3() override { std::cout << "function3() from DeriveClasses.\n"; };
};

/*
    Class diagram:
	                  Base 
					/     \
				   /       \    both public inheritance
				  /	        \
			  Derive1     Derive2
			      \         /
				   \       /   multiple public inheritance
				    \     /
				  DeriveClasses

	The output of the program 

	(Test1):
		This is Base.
		This is Derive1.
		This is Derive2.
		This is DeriveClasses.
		function1() from Derive1.
		function2() from Derive2.
		function3() from DeriveClasses.

    (Test2):
		This is Base.
		This is Derive1.
		Copy constructor from Base.
		function1() from Base.
		function1() from Derive1.
		function1() from Derive1.



    Continue the question from 18.3, why I can have Base* and Base* work but not just Base?
	According to https://docs.microsoft.com/en-us/cpp/cpp/explicitly-defaulted-and-deleted-functions?view=msvc-170,
	the compiler automatically generates the default constructor, copy constructor, copy-assignment operator, and 
	destructor for a type if it does not declar its own. 
	So, from test2, when I have Base base = derive1, I am asking an instance of Base which is a copy of Derive1. 
	Base will not contain some of Derive1's members because Base does not know what members Derive1 has. 
	Thus, only the base portion gets copied.

	Object of derived class has properties of derived class + properties of base class. A derived class is a base class. 

	The Base* and Base& will be getting the memory address of Derive1; they don't call the copy constructors at all.
	So, when the compiler is looking for function definitions, it will already be in the Derive1 class memory section. 

*/

/*
int main() {
	std::cout << "Test1:\n";
	DeriveClasses derive_classes;
	derive_classes.function1();
	derive_classes.function2();
	derive_classes.function3();

	std::cout << "\nTest2:\n";
	Derive1 derive1;
	Base base{ derive1 }; //call copy constructor from Base.
	Base* base_ptr{ &derive1 };
	Base& base_ref{ derive1 };

	base.function1();
	base_ptr->function1();
	base_ref.function1();

	return 0;
}
*/