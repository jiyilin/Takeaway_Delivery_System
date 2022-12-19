#pragma once

#ifndef CLIENT_H
#define CLIENT_H

#include"Kernel.h"

#include"UserTreeNode.h"

class Client : private Kernel
{
private:
	User* useNow;
	bool ClientMenu();
	void CLientUI();
	bool ClientPro(int button);
	bool LoadClient();
public:
	void ClientStart();
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