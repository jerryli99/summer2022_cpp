#include "root_user.h"

#include <iostream>
#include <string>

using namespace std;

/*
           User (base class)
               |
               | (public inheritance)
               |
        RootUser (derived class)


*/
int main() {
	RootUser* root = new RootUser();

	cout << "Get root permission number: " << root->get_file_permission_number() << "\n\n";
	cout << "Changed the protected member (in base)\nto public member (in derived). \nOutput user_file_permission number: " << 
		root->m_user_file_permission << "\n\n";

	root->m_user_file_permission = 6;

	cout << "Changed the user_file_permission number from 4 to -> " << root->m_user_file_permission << "\n";

	return 0;
}