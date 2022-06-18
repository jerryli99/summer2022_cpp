#include "domestic_animal.h"
#include "dog.h"
#include "cat.h"
#include "husky.h"
#include "boxer.h"
#include "persian.h"
#include "calico.h"

#include <iostream>
#include <string>

/*
						  Hierarchical Inheritance

							Domesticated Animals
							   /             \
							 Dog             Cat
						   /     \         /     \
					   Husky    Boxer   Persian  Calico

*/

int main() {
	DomesticAnimal* cow = new DomesticAnimal();
	DomesticAnimal* animal = new Calico(2, 34.5, "Kate");
	Dog* my_dog = new Husky(1, 120, "Cliff");
	Cat* my_cat = new Persian(4, 40, "Kitty");
	Cat* my_second_cat = new Calico(1, 10.9, "Kitty2");
	Calico* calico_cat = new Calico(3, 12.0, "sample1");


	cout << cow->get_name() << "\n";
	cout << animal->get_age() << "\n";
	my_dog->DogSound();
	cout << my_cat->get_name() << "\n";
	
	cout << "--------------------------------\n";
	cout << my_second_cat->get_name() << "\n";
	my_second_cat->set_cat_toy("Red Ball");
	cout << my_second_cat->get_cat_toy() << "\n";
	
	cout << "--------------------------------\n";
	calico_cat->AddVisitedPlace("House");
	calico_cat->AddVisitedPlace("street");
	calico_cat->AddVisitedPlace("Woods");
	calico_cat->PlacesTracker();
	return 0;
}