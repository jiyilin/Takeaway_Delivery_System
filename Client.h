#pragma once

#ifndef CLIENT_H
#define CLIENT_H

#include"Kernel.h"

class Client : private Kernel
{
public:
	void ClientStart();
};

#endif // !CLIENT_H