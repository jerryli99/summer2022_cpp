#pragma once
#include <iostream>
#include <string>

//using std::string;
//or 
using namespace std;

class DomesticAnimal {
 public:
	DomesticAnimal();
	~DomesticAnimal();

	int get_age() const;

	double get_weight() const;

	string get_name() const;

 protected:
	 int m_age{0};
	 double m_weight{0.0};
	 string m_name{"No name"};
};