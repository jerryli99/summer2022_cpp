#include "bag.h"
#include "stack.h"
#include "car.h"

#include <iostream>
#include <vector>

int main() {
	Car* car_1 = new Car("Jeep", "Black", "JT-3423");
	Car* car_2 = new Car("Audi", "Gold", "GD-1234");
	Car* car_3 = new Car("Honda", "Red", "JT-3423");
	Car* car_4 = new Car("Toyota", "White", "JT-3111");

	
	Stack<Car>* car_stack = new Stack<Car>(60000);
	car_stack->IsEmpty();
	car_stack->Add(*car_1);
	car_stack->Add(*car_1);
	car_stack->Add(*car_2);
	car_stack->AddTwice(*car_4);
	car_stack->AddTwice(*car_3);
	std::cout << "stack storage size : " << car_stack->StorageSize() << " bytes\n";
	car_stack->Display();


	std::cout << "--------------------\n";
	Bag<Car>* garage = new Bag<Car>(3000);
	garage->Add(*car_1);
	garage->Add(*car_2);
	std::cout << "Garage storage size : " << garage->StorageSize() << " bytes\n";
	garage->Display();


	Bag<Car>* cars = new Stack<Car>(4000);
	cars->Add(*car_2);
	cars->Add(*car_3);
	cars->Display();
	std::cout << "Pop" << "\n";
	cars->Delete();
	cars->Display();

	delete car_1;
	delete car_2;
	delete car_3;
	delete car_4;
};


/* Old Code

if (*car_1 == *car_3) {
		std::cout << "Hello";
}
Bag<Car>garage(3); // Bag can Resize()
Stack<Car>stack_cars(3); // Stack cannot Resize()

std::cout << "Check if garage is empty: " << garage.IsEmpty() << "\n";

garage.Add(*car_1);
garage.Add(*car_2);
garage.Add(*car_2);
garage.Add(*car_3); // test Bag Delete fails here. Needs future testing.
garage.Add(*car_3);
garage.Add(*car_3);

std::cout << "Get garage top index: " << garage.GetTopIndex() << "\n";
garage.Delete(*car_1);
//std::cout << "We have car4: " << garage.Contains(*car_4) << "\n";
std::cout << "Get garage top index: " << garage.GetTopIndex() << "\n";
garage.Delete(*car_2);
std::cout << "Get garage top index: " << garage.GetTopIndex() << "\n";
garage.Delete(*car_3);
std::cout << "Get garage top index: " << garage.GetTopIndex() << "\n";


Bag<int>integers(2);
int one = 1;
int two = 2;
int three = 3;


integers.Add(one);
integers.Add(two);
integers.Add(two);
integers.Add(three);
integers.Add(three);
std::cout << "Get integers top index: " << integers.GetTopIndex() << "\n";
integers.Delete(three);
std::cout << "Get integers top index: " << integers.GetTopIndex() << "\n";
*/
/*
stack_cars.Add(*car_1);
stack_cars.Add(*car_3);
stack_cars.Add(*car_4);

std::cout << "stack_cars top index: " << stack_cars.GetTopIndex() << "\n";
stack_cars.Delete(*car_1);
std::cout << "stack_cars top index: " << stack_cars.GetTopIndex() << "\n";
stack_cars.Delete(*car_3);
std::cout << "stack_cars top index: " << stack_cars.GetTopIndex() << "\n";
*/