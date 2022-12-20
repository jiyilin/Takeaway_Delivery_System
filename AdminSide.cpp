#include "AdminSide.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "UserTreeNode.h"

constexpr auto AdministratorID = "福州大学至诚学院";
constexpr auto AdministratorPassword = "123456";

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
	std::cout << "|| *******       欢迎使用导航系统管理端       ****** ||" << std::endl;
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
		this->OverviewOfUserData();
		break;
	case 2:
		this->UserLogsOff();
		break;
	case 3:
		this->MapViewing();
		break;
	case 4:
		this->MapModifications();
		break;
	default:
		return false;
	}
	return true;
}

void AdminSide::UserLogsOff()
{
	std::string id;
	std::cout << "请输入待删除的用户账号：";
	std::getline(std::cin, id);
	bool isDelete = false;
	auto data = GainUSerData();
	std::ofstream write;
	write.open("./data/UsersData.txt", std::ios_base::out);
	auto search = data;
	while (search->next != nullptr)
	{
		search = search->next;
		if (search->data->GainUserID() == id)
		{
			isDelete = true;
			continue;
		}
		write << search->data->GainUserID() << " " << search->data->GainUserPassword() << std::endl;
	}
	write.close();
	if (isDelete == true)
	{
		std::string txt = "./data/" + id + ".txt";
		remove(txt.c_str());
		std::cout << "删除成功" << std::endl;
	}
	else
	{
		std::cout << "删除失败   未找到改用户" << std::endl;
	}
}

bool AdminSide::AdminSideLoad()
{
	std::string id;
	std::string passowrd;
	std::cout << "请输入管理员账号：";
	std::getline(std::cin, id);
	std::cout << "请输入管理员密码：";
	std::getline(std::cin, passowrd);
	if (id != AdministratorID || passowrd != AdministratorPassword)
	{
		return false;
	}
	return true;
}

void AdminSide::OverviewOfUserData()
{
	auto data = GainUSerData();
	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "用户"
			  << "\t"
			  << "密码" << std::endl;
	while (UserList_Empty(data) == false)
	{
		auto process = UserList_pop_back(data);
		std::cout << process->GainUserID() << "\t" << process->GainUserPassword() << std::endl;
	}
	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "显示完毕" << std::endl;
}

void AdminSide::MapViewing()
{
	std::ifstream read;
	read.open("Map.txt", std::ios_base::in);
	std::ifstream readList;
	readList.open("MapList.txt", std::ios_base::in);
	if (read.is_open() == false || readList.is_open() == false)
	{
		std::cout << "查看失败    地图打开异常" << std::endl;
		return;
	}
	std::string input;

	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "                        地图节点                       " << std::endl;
	while (std::getline(readList, input))
	{
		std::cout << input << std::endl;
	}
	std::cout << "*= ================================================  =*" << std::endl;
	readList.close();

	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "                          地图                         " << std::endl;
	while (std::getline(read, input))
	{
		std::cout << input << std::endl;
	}
	std::cout << "*= ================================================  =*" << std::endl;
	read.close();
}

void AdminSide::MapModifications()
{
	auto lock = system("MapList.txt");
	auto key = system("Map.txt");
	if (key != 0 || lock != 0)
	{
		std::ofstream write1;
		write1.open("MapList.txt", std::ios_base::out);
		write1.close();
		std::ofstream write;
		write.open("Map.txt", std::ios_base::out);
		write.close();
		system("MapList.txt");
		system("Map.txt");
	}
}

void AdminSide::AdminSideStart()
{
	if (this->AdminSideLoad() == false)
	{
		std::cout << "登录失败   管理员账号或密码错误" << std::endl;
		return;
	}
	system("cls");
	while (this->AdminSideMenu())
	{
		system("pause");
		system("cls");
	}
	std::cout << "您已安全退出管理员端，欢迎下次使用" << std::endl;
}
