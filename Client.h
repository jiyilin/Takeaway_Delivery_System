#pragma once

#ifndef CLIENT_H
#define CLIENT_H

#include "Kernel.h"

#include "UserTreeNode.h"

class Client : private Kernel
{
private:
	User *useNow;
	bool ClientMenu();
	void CLientUI();
	bool ClientPro(int button);
	bool LoadClient();
	void ChangeUserPassword();
	void UserHistory();
	void DestoryUserTxt();
	void LookForARoute();
	void WriteUserHistoryTxt(std::string From, std::string To);
public:
	void ClientStart();
	std::string GainUseNowwID();
	~Client();
};

class ClientSystem : private Kernel
{
private:
	Client Client;
	bool ClientSystemMenu();
	void CLientSystemUI();
	bool ClientSystemPro(int button);
	void RegisteredUsers();

public:
	void ClientSystemStart();
};

#endif // !CLIENT_H