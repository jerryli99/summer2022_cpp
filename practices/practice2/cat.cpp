#include "cat.h"

Cat::Cat() {}
Cat::~Cat() {}

void Cat::CatSound() {
	std::cout << "Meow\n";
}

void Cat::set_cat_toy(const string& toy_name) {
	m_favorite_toy = toy_name;
}

string Cat::get_cat_toy() const {
	return m_favorite_toy;
}

