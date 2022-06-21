#pragma once

#include <iostream>
#include <string>

using namespace std;

class Book {
public:
	Book(string title, string author, string book_isbn, int pages, double book_price);
	~Book();

	//use the friend keyword to access private members, and overload operator<<
	friend ostream& operator<<(ostream& out, const Book& book);

private: 
	string m_book_title{ "None" };
	string m_book_author{ "None" };
	string m_book_isbn{ 0 };
	int m_pages{ 0 };
	double m_book_price{ 0.0 };

};