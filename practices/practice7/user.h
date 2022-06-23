#pragma once

class User {
public:
	User();
	~User();

	int get_file_permission_number() const;

protected:
	int m_user_file_permission{ 4 };

private:
	//int m_user_file_permission{ 4 };
};