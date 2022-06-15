#include <iostream>
#include <string>
/*
*						      Hierarchical Inheritance
* 
							Domesticated Animals
							   /             \
							 Dog             Cat
                           				/     \         /     \
					   	    Husky    Boxer   Persian  Calico

*/

class DomesticAnimal{
public:
	DomesticAnimal() : m_age(0), m_weight(0), m_name("No name") {}
	~DomesticAnimal() {}

	int get_age() const {
		return m_age;
	}

	double get_weight() const {
		return m_weight;
	}

	std::string get_name() const {
		return m_name;
	}

protected:
	int m_age;
	double m_weight;
	std::string m_name;
};

class Dog : public DomesticAnimal {
 public:
	Dog() {};
	~Dog() {};
	void DogSound() {
		std::cout << "Woof\n";
	}
};

class Cat : public DomesticAnimal {
 public:
	Cat() {};
	~Cat() {};
	void CatSound() {
		std::cout << "Meow\n";
	}
};

class Husky : public Dog {
public:
	Husky(int age, double weight, std::string name) {
		this->m_age = age;
		this->m_weight = weight;
		this->m_name = name;
	}
	~Husky() {}

};

class Boxer : public Dog {
public:
	Boxer(int age, double weight, std::string name) {
		this->m_age = age;
		this->m_weight = weight;
		this->m_name = name;
	}
	~Boxer() {}
};

class Persian : public Cat {
public:
	Persian(int age, double weight, std::string name) {
		this->m_age = age;
		this->m_weight = weight;
		this->m_name = name;
	}
	~Persian() {}
};

class Calico : public Cat {
public:
	Calico(int age, double weight, std::string name) {
		this->m_age = age;
		this->m_weight = weight;
		this->m_name = name;
	}
	~Calico() {}
};

int main() {
	DomesticAnimal* cow = new DomesticAnimal();
	DomesticAnimal* animal = new Calico(2, 34.5, "Kate");
	Dog* my_dog = new Husky(1, 120, "Cliff");
	Cat* my_cat = new Persian(4, 40, "Kitty");

	std::cout << cow->get_name() << "\n";
	std::cout << animal->get_age() << "\n";
	my_dog->DogSound();
	std::cout << my_cat->get_name() << "\n";
}
