#include "my_friend.h"

MyFriend::MyFriend(string name, unsigned student_id) 
	: Student{ name, student_id } {};

MyFriend::MyFriend(string name, unsigned student_id, string nickname,
	string country, vector<string>& languages)
	: Student{ name, student_id }, Person{ nickname, country, languages } {};

MyFriend::~MyFriend() {};

void MyFriend::set_relation_years(int years) {
	m_relation_years = years;
}

int MyFriend::get_relation_years() const {
	return m_relation_years;
}
string MyFriend::get_friend_nickname() const {
	return m_nickname;
};

