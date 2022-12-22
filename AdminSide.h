#pragma once

#ifndef ADMINSIDE_H
#define ADMINSIDE_H

#include "Kernel.h"

class AdminSide : private Kernel
{
private:
	bool AdminSideMenu();
	void AdminSideUI();
	bool AdminSidePro(int button);
	void UserLogsOff();
	bool AdminSideLoad();
	void OverviewOfUserData();
	void MapViewing();
	void MapModifications();
	void MapModificationsUI();
	void MapModificationsPro(int button);
	void MapModificationsMenu();
	void ModifyMapFromAFile();
public:
	void AdminSideStart();
};

#endif // !ADMINSIDE_H
