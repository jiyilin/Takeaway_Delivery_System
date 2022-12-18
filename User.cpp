#include "User.h"

User::User(std::string name, std::string cipher)
{
	this->id = name;
	again:
	if (cipher.length() < 6 || cipher.length() > 15)
	{
		std::cout << "密码应大于5位，小于16位!!!    请重新输入:";
		std::getline(std::cin, cipher);
		goto again;
	}
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

std::string User::GainStartingPoint()
{
	return this->startingPoint;
}

std::string User::GainDestination()
{
	return this->destination;
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
		std::cout << "密码修改成功" << std::endl;
		return true;
	}
}

bool User::SetUserStartingPoint(std::string lock)
{
	if (this->startingPoint == lock)
	{
		return false;
	}
	this->startingPoint = lock;
	return true;
}

bool User::SetUserDestination(std::string lock)
{
	if (this->destination == lock)
	{
		return false;
	}
	this->destination = lock;
	return true;
}

