#include "User.h"

User::User(std::string name, std::string cipher)
{
	this->id = name;
	again:
	if (cipher.length() < 6 || cipher.length() > 15)
	{
		std::cout << "����Ӧ����5λ��С��16λ!!!    ����������:";
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
		std::cout << "�����޸�ʧ��!!!   ����Ӧ����5λ��С��16λ" << std::endl;
		return false;
	}
	else
	{
		std::cout << "�����޸ĳɹ�" << std::endl;
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

