#include "student.h"

Student::Student(string name, unsigned student_id) 
	: m_student_name{ name }, m_student_id{ student_id} {};

Student::~Student() {};

void Student::set_first_exam_score(float score) {
	m_first_exam_score = score;
};

void Student::set_second_exam_score(float score) {
	m_second_exam_score = score;
};

void Student::set_final_exam_score(float score) {
	m_final_exam_score = score;
};

float Student::get_first_exam_score() const {
	return m_first_exam_score;
}

float Student::get_second_exam_score() const {
	return m_second_exam_score;
}

float Student::get_final_exam_score() const {
	return m_final_exam_score;
}

ostream& operator<<(ostream& out, const Student& student) {
	out << "Student name: " << student.m_student_name << "\n"
		<< "  Student ID:   " << student.m_student_id << "\n";

	return out;
}