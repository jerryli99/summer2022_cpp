#include "teacher_portal.h"

TeacherPortal::TeacherPortal(StemTeacher* stem_teacher) 
	: m_stem_teacher{ stem_teacher } {};

TeacherPortal::~TeacherPortal() {};

void TeacherPortal::AddStudent(string course_name, Student& student) {
	m_class_map[course_name].push_back(student);
}

void TeacherPortal::DisplayClassMap() {
	cout << *m_stem_teacher << "\n";
	m_stem_teacher->OnlineClass();
	m_stem_teacher->InPersonClass();
	m_stem_teacher->ShowBooks();
	cout << "{\n";
	for (const auto& key : m_class_map) {
		cout << key.first << ":\n [\n";
		for (const auto& student : key.second) {
			cout << "  " << student
			   	 << "  Student exam1 score: " << student.get_final_exam_score() << "\n"
				 << "  Student exam2 score: " << student.get_second_exam_score() << "\n"
				 << "  Student final exam score: " << student.get_final_exam_score() << ",\n\n";
		}
		cout << " ],\n";
	}
	cout << "}\n";
}