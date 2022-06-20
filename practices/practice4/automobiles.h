#pragma once

#include <iostream>
#include <string>

using namespace std;

class Automobiles {
public:
	Automobiles(string color = "None", string owner_name = "None");
	~Automobiles();

	string m_automobile_color{ "None" };
	string m_automobile_name{ "None" };

	string get_owner_name() const {
		return m_automobile_owner;
	}

protected:
	int m_automobile_seats{ 0 };

private:
	string m_automobile_owner;
};