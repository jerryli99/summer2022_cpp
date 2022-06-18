#pragma once
#include "domestic_animal.h"
#include <vector>

class Cat : public DomesticAnimal {
 public:
	Cat();
	~Cat();
	void CatSound();
	string get_cat_toy() const;
	void set_cat_toy(const string& toy_name);

 protected:
	 vector<string> m_visited_places{"Start->"};

 private:
	string m_favorite_toy{ "None" }; //uniform initialization

	//setter and getter canno be accessed after created a Calico instance.
	//void set_cat_toy(const string& toy_name);
	//string get_cat_toy() const;

};
