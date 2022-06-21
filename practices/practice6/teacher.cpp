#include "teacher.h"

Teacher::Teacher(string teacher_name, string teaching_field, string degree, float experience_years)
	: m_teacher_name{ teacher_name }, m_teaching_field{ teaching_field },
	m_degree{ degree }, m_teaching_experience_years{ experience_years } {};

Teacher::~Teacher() {};

void Teacher::OnlineClass() {
	cout << "Teach online class\n\n";
}

void Teacher::InPersonClass() {
	cout << "Teach in person class\n\n";
}

ostream& operator<<(ostream& out, const Teacher& teacher) {
	out << "Teacher name:     " << teacher.m_teacher_name
		<< "\nTeaching field:   " << teacher.m_teaching_field
		<< "\nTeaching years:   " << teacher.m_teaching_experience_years 
		<< "\n";

	return out;
}