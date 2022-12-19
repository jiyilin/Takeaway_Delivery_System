#include "Client.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdio>

#include "User.h"
#include "HistoryList.h"
#include "Map.h"

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
	std::cout << "|| *******       欢迎使用导航系统客户端       ****** ||" << std::endl;
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

void GainID(std::string &lock)
{
	std::string key;
	for (int i = 0; i < lock.size(); i++)
	{
		if (lock[i] == ' ')
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

	if (idInput.length() == 0 || passwordInput.length() == 0)
	{
		std::cout << "注册失败，账号密码不能为空" << std::endl;
		return;
	}

	std::string process;

	std::ifstream read;
	read.open("./data/UsersData.txt", std::ios_base::in);
	while (std::getline(read, process))
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
	std::ofstream writeHistory;
	writeHistory.open("./data/" + idInput + ".txt", std::ios_base::app);
	writeHistory.close();
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
	auto button = this->GainMenuChoose(4, true);
	if (this->ClientPro(button) == false)
	{
		return false;
	}
	return true;
}

void Client::CLientUI()
{
	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "|| *******      欢迎使用导航系统客户端        ****** ||" << std::endl;
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
		this->LookForARoute();
		break;
	case 2:
		this->UserHistory();
		break;
	case 3:
		this->ChangeUserPassword();
		break;
	case 4:
		std::cout << "账号注销成功" << std::endl;
		this->DestoryUserTxt();
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
	else if (UserLoad(id, password, this->useNow))
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

void Client::UserHistory()
{
	std::string txt;
	txt = "./data/" + this->useNow->GainUserID() + ".txt";
	std::ifstream read;
	read.open(txt, std::ios_base::in);
	std::string input;
	auto data = HistoryList_Init();
	while (std::getline(read, input))
	{
		HistoryList_push_back(data, input);
	}
	read.close();
	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "                        历史记录                       " << std::endl;
	while (HistoryList_Empty(data) == false)
	{
		std::cout << HistoryList_pop_Back(data) << std::endl;
	}
	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "显示完成" << std::endl;
}

void Client::DestoryUserTxt()
{
	std::string txt = "./data/" + this->useNow->GainUserID() + ".txt";
	remove(txt.c_str());
}

void Client::LookForARoute()
{
	std::cout << "请输入出发地点：";
	std::string From;
	std::getline(std::cin, From);
	std::cout << "请输入到达地点：";
	std::string To;
	std::getline(std::cin, To);
	Map data;
	if (data.ReadMapList() == false)
	{
		return;
	}
	if (data.SEARCH_MAP(To) == false || data.SEARCH_MAP(From) == false)
	{
		std::cout << "查找失败，地图无该地点" << std::endl;
		return;
	}
	data.GainRoute(From, To);
	data.Print_Route();
	this->WriteUserHistoryTxt(From, To);
}

void Client::WriteUserHistoryTxt(std::string From, std::string To)
{
	std::ofstream write;
	write.open("./data/" + useNow->GainUserID() + ".txt", std::ios_base::app);
	SYSTEMTIME time;
	GetLocalTime(&time);
	write << "从 " << From << "到 " << To << " " << time.wYear << ":" << time.wMonth << ":" << time.wDay << ":" << time.wHour << ":" << time.wMinute << ":" << time.wSecond << std::endl;
	write.close();
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
