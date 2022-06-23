#pragma once

#include "user.h"

class RootUser : public User {
public:
	RootUser();
	~RootUser();

	//Cannot change to public because m_user_file_permission 
	//is private in class User
	//using User::m_user_file_permission;

	//Change m_user_file_permission in class User from protected to public.
	//This works because m_user_file_permission is protected in class User.
	using User::m_user_file_permission;

	int get_file_permission_number() const;

private:
	//Change m_user_file_permission in class User from protected to private.
	//This works because m_user_file_permission is protected in class User.
	//using User::m_user_file_permission;

	int m_root_file_permission{ 7 };
};