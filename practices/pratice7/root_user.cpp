#include "root_user.h"

RootUser::RootUser() {};

RootUser::~RootUser() {};

int RootUser::get_file_permission_number() const {
	return m_root_file_permission;
}
