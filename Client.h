#pragma once

#ifndef CLIENT_H
#define CLIENT_H

#include"Kernel.h"

class Client : private Kernel
{
private:
	bool ClientMenu();
	void CLientUI();
	bool ClientPro(int button);
	bool LoadClient();
public:
	void ClientStart();
};

class ClientSystem : private Kernel
{
private:
	Client Client;
	bool ClientSystemMenu();
	void CLientSystemUI();
	bool ClientSystemPro(int button);
public:
	void ClientSystemStart();
};

#endif // !CLIENT_H