#include "Client.h"
#include<iostream>

bool ClientSystem::ClientSystemMenu()
{
	this->CLientSystemUI();
	auto button = this->GainMenuChoose(2, true);
	if (this->ClientSystemPro(button) == false)
	{
		return false;
	}
	return true;
}

void ClientSystem::CLientSystemUI()
{
	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "|| *******     欢迎使用外卖导航系统客户端     ****** ||" << std::endl;
	std::cout << "|| *              1. 登录                          * ||" << std::endl;
	std::cout << "|| *              2. 注册                          * ||" << std::endl;
	std::cout << "|| *              0. 退出                          * ||" << std::endl;
	std::cout << "|| *******                                    ****** ||" << std::endl;
	std::cout << "*= ================================================  =*" << std::endl;
}

bool ClientSystem::ClientSystemPro(int button)
{
	switch (button)
	{
	case 1:
		this->Client.ClientStart();
		return false;
	case 2:
		std::cout << "注册" << std::endl;
		break;
	default:
		return false;
	}
	return true;
}

void ClientSystem::ClientSystemStart()
{
	system("cls");
	while (this->ClientSystemMenu())
	{
		system("pause");
		system("cls");
	}
	std::cout << "您已安全退出客户端，欢迎下次使用" << std::endl;
}

bool Client::ClientMenu()
{
	this->CLientUI();
	auto button = this->GainMenuChoose(4,true);
	if (this->ClientPro(button) == false )
	{
		return false;
	}
	return true;
}

void Client::CLientUI()
{
	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "|| *******     欢迎使用外卖导航系统客户端     ****** ||" << std::endl;
	std::cout << "|| *              1. 寻找线路                      * ||" << std::endl;
	std::cout << "|| *              2. 历史记录                      * ||" << std::endl;
	std::cout << "|| *              3. 修改密码                      * ||" << std::endl;
	std::cout << "|| *              4. 账号注销                      * ||" << std::endl;
	std::cout << "|| *              0. 退出                          * ||" << std::endl;
	std::cout << "|| *******                                    ****** ||" << std::endl;
	std::cout << "*= ================================================  =*" << std::endl;
}

bool Client::ClientPro(int button)
{
	switch (button)
	{
	case 1:
		std::cout << "寻找线路" << std::endl;
		break;
	case 2:
		std::cout << "历史记录" << std::endl;
		break;
	case 3:
		std::cout << "修改密码" << std::endl;
		break;
	case 4:
		std::cout << "账号注销" << std::endl;
		break;
	default:
		return false;
	}
	return true;
}

bool Client::LoadClient()
{
	return true;
}

void Client::ClientStart()
{
	system("cls");
	if (this->LoadClient() == false)
	{
		std::cout << "登录失败!!!   账号或密码错误" << std::endl;
		return;
	}
	while (this->ClientMenu())
	{
		system("pause");
		system("cls");
	}
}
