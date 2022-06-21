#include "book.h"

Book::Book(string title, string author, string book_isbn, int pages, double book_price)
	: m_book_title{ title }, m_book_author{ author }, 
	  m_book_isbn{ book_isbn }, m_pages{ pages }, 
	  m_book_price{ book_price } {};

Book::~Book() {};


ostream& operator<<(ostream& out, const Book& book)
{
	out << "Book title:  " << book.m_book_title
		<< "\nBook author: " << book.m_book_author
		<< "\nBook ISBN:   " << book.m_book_isbn
		<< "\nBook pages:  " << book.m_pages
		<< "\nBook price:  " << "$" << book.m_book_price << "\n";

	return out;
}