#include "User.h"

User::User(std::string name, std::string cipher)
{
	this->id = name;
	this->password = cipher;
}

User::~User() = default;

std::string User::GainUserID()
{
	return this->id;
}

std::string User::GainUserPassword()
{
	return this->password;
}

bool User::JudgmentUserLoad(std::string cipher)
{
	if (this->password == cipher)
	{
		return true;
	}
	return false;
}

bool User::SetUserPassword(std::string lock)
{
	if (lock.length() < 6 || lock.length() > 15)
	{
		std::cout << "密码修改失败!!!   密码应大于5位，小于16位" << std::endl;
		return false;
	}
	else
	{
		this->password = lock;
		std::cout << "密码修改成功" << std::endl;
		return true;
	}
}
