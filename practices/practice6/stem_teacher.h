#pragma once

#include "teacher.h"
#include "student.h"
#include "book.h"

#include <vector>

class StemTeacher : public Teacher {
public:
	StemTeacher(string teacher_name, string teaching_field, string degree, float experience_years);
	~StemTeacher();

	void AddBooks(const Book& book);
	void ShowBooks();

	//this function overrides the function void InPersonClass() 
	//in class Teacher (the base class of class StemTeacher)
	void InPersonClass(); 


private:
	vector<Book> m_required_books{};
};