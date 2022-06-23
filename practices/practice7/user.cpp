#include "user.h"

User::User() {};

User::~User() {};

int User::get_file_permission_number() const {
	return m_user_file_permission;
}
