#pragma once

#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	Student(string name, unsigned student_id);
	~Student();

	void set_first_exam_score(float score);
	void set_second_exam_score(float score);
	void set_final_exam_score(float score);

	float get_first_exam_score() const;
	float get_second_exam_score() const;
	float get_final_exam_score() const;

	friend ostream& operator<<(ostream& out, const Student& student);

protected:
	string m_student_name{ "None" };

private:
	unsigned m_student_id{ 0 };
	float m_first_exam_score{ 0.0 };
	float m_second_exam_score{ 0.0 };
	float m_final_exam_score{ 0.0 };
};