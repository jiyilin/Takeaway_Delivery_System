#pragma once

#ifndef ADMINSIDE_H
#define ADMINSIDE_H

#include"Kernel.h"

class AdminSide : private Kernel
{
private:
	bool AdminSideMenu();
	void AdminSideUI();
	bool AdminSidePro(int button);
public:
	void AdminSideStart();
};

#endif // !ADMINSIDE_H
