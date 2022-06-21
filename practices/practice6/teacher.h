#pragma once

#include <iostream>
#include <string>

using namespace std;

//base class of StemTeacher
class Teacher {
public:
	Teacher(string teacher_name, string teaching_field, string degree, float experience_years);
	~Teacher();

	void OnlineClass();
	void InPersonClass();

	friend ostream& operator<<(ostream& out, const Teacher& teacher);

private:
	string m_teacher_name{ "None" };
	string m_teaching_field{ "None" };
	string m_degree{ "None" };
	float m_teaching_experience_years{ 0.0 };
};