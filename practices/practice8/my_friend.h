#pragma once

#include "student.h"
#include "person.h"

class MyFriend : public Student, public Person {
public:
	MyFriend(string name, unsigned student_id);
	MyFriend(string name, unsigned student_id, string nickname, 
		     string country, vector<string>& languages);
	~MyFriend();

	//change protected to public 
	//from class Student and class Person
	using Student::m_student_name;
	using Person::m_languages;
	using Person::m_country;

	void set_relation_years(int years);
	int get_relation_years() const;
	string get_friend_nickname() const;

private:
	int m_relation_years{ 0 };

	//My friend doesn't want to reveal his nickname
	//to other people except me.
	using Person::m_nickname;
};