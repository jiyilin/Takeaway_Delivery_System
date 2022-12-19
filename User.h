#pragma once

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User
{
private:
	std::string id;
	std::string password;

public:
	User(std::string name, std::string cipher);
	~User();
	std::string GainUserID();
	std::string GainUserPassword();

	bool JudgmentUserLoad(std::string cipher);

	bool SetUserPassword(std::string lock);
};

#endif // !USER_H
