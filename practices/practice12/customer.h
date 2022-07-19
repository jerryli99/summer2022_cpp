#pragma once

#include <iostream>

using namespace std;

/*
	I was going to make struct Customer since it is just data. 
	However, I still want it to be OOP more and have encapsulation
	more clear, so I still use class here.
*/
class Customer {
public:
	Customer() = default;
	Customer(string name, string email, string phone, string order_detail);
	~Customer();

private:
	string m_name{ "None" };
	string m_email{ "None" };
	string m_phone{ "None" };
	string m_order_detail{ "None" };

	friend std::ostream& operator<<(std::ostream& output, const Customer& customer);
};