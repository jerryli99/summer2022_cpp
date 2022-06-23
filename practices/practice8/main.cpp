#include "my_friend.h"
#include "person.h"
#include "student.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
             Multiple inheritance

        Student (base)    Person (base)
              \              /     
               \            /
                \          /
              MyFriend (derived)
*/
int main() {
	vector<string> friend_languages = { "English", "Spanish", "Chinese" };

	//my friend in school
	MyFriend* my_friend1 = new MyFriend("John", 123456);

	//my friend in school and work
	MyFriend* my_friend2 = new MyFriend("Joe", 654321, "Jones", "North America", friend_languages);

	my_friend1->set_first_exam_score(100);
	my_friend1->set_final_exam_score(90);

	my_friend1->set_relation_years(2);
	cout << "I am friends with " << my_friend1->m_student_name << " for " << my_friend1->get_relation_years() << " years.\n";
	cout << "He got " << my_friend1->get_first_exam_score() << "% on his first exam and "
		 << my_friend1->get_final_exam_score() << "% on his final.\n\n";

	cout << "My second friend speaks: ";
	for (const auto& element : my_friend2->m_languages) {
		cout << element << " ";
	}
	cout << "\n";
	cout << "His nick name is " << my_friend2->get_friend_nickname() << ". He is from " << my_friend2->m_country <<"\n";

	return 0;
}