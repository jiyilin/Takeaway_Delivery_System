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
		std::cout << "�����޸�ʧ��!!!   ����Ӧ����5λ��С��16λ" << std::endl;
		return false;
	}
	else
	{
		this->password = lock;
		std::cout << "�����޸ĳɹ�" << std::endl;
		return true;
	}
}
