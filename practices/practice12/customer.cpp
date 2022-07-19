#include "customer.h"

Customer::Customer(
	string name, 
	string email, 
	string phone, 
	string order_detail
)
	: m_name{ name }, 
	  m_email{ email }, 
	  m_phone{ phone }, 
	  m_order_detail{ order_detail } {};

Customer::~Customer() {}


std::ostream& operator<<(std::ostream& output, const Customer& customer) {
	return output << "{\n " <<
		customer.m_name << "\n " <<
		customer.m_email << "\n " <<
		customer.m_phone << "\n " <<
		customer.m_order_detail << "\n}\n";
}
