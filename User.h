#pragma once

#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>

class User
{
private:
	std::string id;
	std::string password;
	std::string startingPoint;
	std::string destination;
public:
	User(std::string name, std::string cipher);
	~User();
	std::string GainUserID();
	std::string GainUserPassword();
	std::string GainStartingPoint();
	std::string GainDestination();

	bool JudgmentUserLoad(std::string cipher);

	bool SetUserPassword(std::string lock);
	bool SetUserStartingPoint(std::string lock);
	bool SetUserDestination(std::string lock);
};

#endif // !USER_H
