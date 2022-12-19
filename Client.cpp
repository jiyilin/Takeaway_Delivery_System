#include "Client.h"
#include<iostream>
#include<fstream>
#include<string.h>

#include"User.h"

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
		this->RegisteredUsers();
		break;
	default:
		return false;
	}
	return true;
}

void GainID(std::string& lock)
{
	std::string key;
	for (int i = 0; i < lock.size(); i++)
	{
		if (lock[i]==' ')
		{
			break;
		}
		key.push_back(lock[i]);
	}
	key = lock;
}


void ClientSystem::RegisteredUsers()
{
	std::string idInput;
	std::string passwordInput;
	std::cout << "请输入账号：";
	std::getline(std::cin, idInput);
	std::cout << "请输入密码(密码应大于5位，小于16位)：";
	std::getline(std::cin, passwordInput);
	std::string process;

	std::ifstream read;
	read.open("./data/UsersData.txt", std::ios_base::in);
	while (std::getline(read,process))
	{
		GainID(process);
		if (process == idInput)
		{
			std::cout << "注册失败!!!   该用户已被注册" << std::endl;
			read.close();
			return;
		}
	}
	read.close();

	std::ofstream write;
	write.open("./data/UsersData.txt", std::ios_base::app);
	write << idInput << " " << passwordInput << std::endl;
	write.close();
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
		this->ChangeUserPassword();
		break;
	case 4:
		std::cout << "账号注销成功" << std::endl;
		return false;
	default:
		std::ofstream write;
		write.open("./data/UsersData.txt", std::ios_base::app);
		write << useNow->GainUserID() << " " << useNow->GainUserPassword() << std::endl;
		write.close();
		return false;
	}
	return true;
}

bool Client::LoadClient()
{
	std::string id;
	std::string password;
	std::cout << "请输入账号：";
	std::getline(std::cin, id);
	std::cout << "请输入密码：";
	std::getline(std::cin, password);
	if (id.length() == 0 || password.length() == 0)
	{
		std::cout << "登录失败    账号密码不能为空" << std::endl;
	}
	else if (UserLoad(id,password,this->useNow))
	{
		std::cout << "登录成功" << std::endl;
		system("pause");
		system("cls");
		return true;
	}
	return false;
}

void Client::ChangeUserPassword()
{
	std::string oldPassword;
	std::string newPassowrd;
	std::cout << "请输入原密码：";
	std::getline(std::cin, oldPassword);
	if (oldPassword != this->useNow->GainUserPassword())
	{
		std::cout << "密码修改失败!!!   密码输入错误" << std::endl;
		return;
	}
	std::cout << "请输入新密码：";
	std::getline(std::cin, newPassowrd);
	if (oldPassword == newPassowrd)
	{
		std::cout << "密码修改失败!!!   原密码与新密码一致" << std::endl;
		return;
	}
	this->useNow->SetUserPassword(newPassowrd);
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

Client::~Client() = default;
