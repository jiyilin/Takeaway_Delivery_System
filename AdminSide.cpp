#include "AdminSide.h"
#include<iostream>

bool AdminSide::AdminSideMenu()
{
	this->AdminSideUI();
	auto button = this->GainMenuChoose(4, true);
	if (this->AdminSidePro(button) == false)
	{
		return false;
	}
	return true;
}

void AdminSide::AdminSideUI()
{
	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "|| *******     欢迎使用外卖导航系统管理端     ****** ||" << std::endl;
	std::cout << "|| *              1. 用户数据全览                  * ||" << std::endl;
	std::cout << "|| *              2. 用户注销                      * ||" << std::endl;
	std::cout << "|| *              3. 地图查看                      * ||" << std::endl;
	std::cout << "|| *              4. 地图修改                      * ||" << std::endl;
	std::cout << "|| *              0. 退出                          * ||" << std::endl;
	std::cout << "|| *******                                    ****** ||" << std::endl;
	std::cout << "*= ================================================  =*" << std::endl;
}

bool AdminSide::AdminSidePro(int button)
{
	switch (button)
	{
	case 1:
		std::cout << "用户数据全览" << std::endl;
		break;
	case 2:
		std::cout << "用户注销" << std::endl;
		break;
	case 3:
		std::cout << "地图查看" << std::endl;
		break;
	case 4:
		std::cout << "地图修改" << std::endl;
		break;
	default:
		return false;
	}
	return true;
}

void AdminSide::AdminSideStart()
{
	system("cls");
	while (this->AdminSideMenu())
	{
		system("pause");
		system("cls");
	}
	std::cout << "您已安全退出管理员端，欢迎下次使用" << std::endl;
}
