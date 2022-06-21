#include "stem_teacher.h"

StemTeacher::StemTeacher(string teacher_name, string teaching_field, string degree, float experience_years) :
	Teacher{ teacher_name, teaching_field, degree, experience_years } {};

StemTeacher::~StemTeacher() {};

void StemTeacher::AddBooks(const Book& book) {
	m_required_books.push_back(book);
}

void StemTeacher::ShowBooks() {
	cout << "Books students are required to use: \n\n";
	for (const auto& element : m_required_books) {
		cout << element << "\n";
	}
}

//override Teacher::InPersonClass()
void StemTeacher::InPersonClass() {
	cout << "StemTeachers do not have in person classes\n\n";
}