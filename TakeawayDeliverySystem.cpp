#include "TakeawayDeliverySystem.h"
#include <Windows.h>
#include<iostream>

bool TakeawayDeliverySystem::EngineDetection()
{
	if (GetFileAttributesA("data") == INVALID_FILE_ATTRIBUTES)
	{
		if (system("md data") == 0)
		{
			std::cout << "程序未添加数据库，已创建新数据库" << std::endl;
			system("pause");
		}
		else
		{
			std::cout << "程序启动失败，数据库未通过检测" << std::endl;
			system("pause");
			return false;
		}
	}
	system("cls");
	return true;
}

void TakeawayDeliverySystem::EngineStarts()
{
	while (this->TakeawayDeliverySystemMenu())
	{
		system("pause");
		system("cls");
	}
	std::cout << "您已安全退出程序，欢迎下次使用" << std::endl;
}

bool TakeawayDeliverySystem::TakeawayDeliverySystemMenu()
{
	this->TakeawayDeliverySystemUI();
	auto button = this->GainMenuChoose(2,true);
	if (this->TakeawayDeliverySystemPro(button) == false)
	{
		return false;
	}
	return true;
}

void TakeawayDeliverySystem::TakeawayDeliverySystemUI()
{
	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "|| *******        欢迎使用外卖导航系统        ****** ||" << std::endl;
	std::cout << "|| *              1. 客户端                        * ||" << std::endl;
	std::cout << "|| *              2. 管理员端                      * ||" << std::endl;
	std::cout << "|| *              0. 退出                          * ||" << std::endl;
	std::cout << "|| *******                                    ****** ||" << std::endl;
	std::cout << "*= ================================================  =*" << std::endl;
}

bool TakeawayDeliverySystem::TakeawayDeliverySystemPro(int button)
{
	switch (button)
	{
	case 1:
		this->client.ClientStart();
		break;
	case 2:
		this->adminSide.AdminSideStart();
		break;
	default:
		return false;
	}
	return true;
}
