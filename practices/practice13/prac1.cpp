#include <iostream>

class Base {
 public:
	virtual void f1() { std::cout << "Base f1()\n."; }
	virtual void f2() { std::cout << "Base f2()\n."; }
};


class Derive1 : public Base {
 public:
	void f1() override { std::cout << "Derive1 f1().\n"; }
};


class Derive2 : public Base {
 public:
	void f2() override { std::cout << "Derive2 f2().\n"; }
};

/*
int main() {
	Derive1 derive1;
	Derive2 derive2;

	Base* base_ptr = &derive1;
	base_ptr->f1();
	base_ptr->f2();

	base_ptr = &derive2;
	base_ptr->f1();
	base_ptr->f2();

	return 0;
}
*/