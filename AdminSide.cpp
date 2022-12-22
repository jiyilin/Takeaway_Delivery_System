﻿#include "AdminSide.h"
#include <iostream>
#include <fstream>
#include<sstream>
#include <string>
#include <cstdio>

#include "UserTreeNode.h"
#include"StringVector.h"
#include"StringList.h"

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

void GainMapHistoryString_AdminSide(std::string lock, int& from, int& to, double& distance)
{
	std::string fromString;
	std::string toString;
	std::string distanceString;
	int flag = 0;
	for (int i = 0; i < lock.size(); i++)
	{
		if (lock[i] == ' ')
		{
			flag++;
		}
		if (flag == 0 && lock[i] != ' ')
		{
			fromString.push_back(lock[i]);
		}
		else if (flag == 1 && lock[i] != ' ')
		{
			toString.push_back(lock[i]);
		}
		else if (flag == 2 && lock[i] != ' ')
		{
			distanceString.push_back(lock[i]);
		}
	}
	std::stringstream streamFrom(fromString);
	std::stringstream streamTo(toString);
	std::stringstream streamDistance(distanceString);
	streamFrom >> from;
	streamTo >> to;
	streamDistance >> distance;
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

	//std::cout << "*= ================================================  =*" << std::endl;
	//std::cout << "                        地图节点                       " << std::endl;
	int number = 0;
	//std::cout << "序号" << "\t" << "名称" << std::endl;

	auto* map = new StringVector;
	while (std::getline(readList, input))
	{
		//std::cout << number << "\t" << input << std::endl;
		StringVector_push_back(map, input);
		number++;
	}
	//std::cout << "*= ================================================  =*" << std::endl;
	readList.close();

	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "                          地图                         " << std::endl;
	std::cout << "出发点\t\t\t到达点\t\t\t代价" << std::endl;
	std::getline(read, input);

	auto* data = new StringVector;
	while (std::getline(read, input))
	{
		StringVector_push_back(data, input);
	}
	StringVector_sort(data);

	int from = 0;
	int to = 0;
	double distance = 0.0;
	for (int i = 0; i < StringVector_size(data); i++)
	{
		GainMapHistoryString_AdminSide(data->data[i], from, to, distance);
		std::cout << map->data[from] << "\t\t\t" << map->data[to] << "\t\t\t" << distance << std::endl;
	}

	std::cout << "*= ================================================  =*" << std::endl;
	read.close();
}

void AdminSide::MapModifications()
{
	//auto lock = system("MapList.txt");
	//auto key = system("Map.txt");
	//if (key != 0 || lock != 0)
	//{
	//	std::ofstream write1;
	//	write1.open("MapList.txt", std::ios_base::out);
	//	write1.close();
	//	std::ofstream write;
	//	write.open("Map.txt", std::ios_base::out);
	//	write.close();
	//	system("MapList.txt");
	//	system("Map.txt");
	//}
	this->MapModificationsMenu();
}

void AdminSide::MapModificationsUI()
{
	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "                请选择您要的修改方式                   " << std::endl;
	std::cout << "*   1. 添加节点" << std::endl;
	std::cout << "*   2. 删除节点" << std::endl;
	std::cout << "*   3. 修改节点名称" << std::endl;
	std::cout << "*   4. 添加路线" << std::endl;
	std::cout << "*   5. 删除路线" << std::endl;
	std::cout << "*   6. 修改路线代价" << std::endl;
	std::cout << "*   7. 通过文件修改" << std::endl;
	std::cout << "*   0. 取消" << std::endl;
	std::cout << "*= ================================================  =*" << std::endl;
}

void AdminSide::MapModificationsPro(int button)
{
	switch (button)
	{
	case 1:
		this->MapAddNode();
		break;
	case 2:
		std::cout << "*   2. 删除节点" << std::endl;
		break;
	case 3:
		this->MapModifyNodeName();
		break;
	case 4:
		std::cout << "*   4. 添加路线" << std::endl;
		break;
	case 5:
		std::cout << "*   5. 删除路线" << std::endl;
		break;
	case 6:
		std::cout << "*   6. 修改路线" << std::endl;
		break;
	case 7:
		this->ModifyMapFromAFile();
		break;
	default:
		return;
		break;
	}
}

void AdminSide::MapModificationsMenu()
{
	MapModificationsUI();
	auto button = this->GainMenuChoose(7, true);
	this->MapModificationsPro(button);
}

void AdminSide::ModifyMapFromAFile()
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

StringList* ReadMapListTxt()
{
	std::ifstream read;
	read.open("MapList.txt", std::ios_base::in);
	auto data = StringList_init();
	std::string input;
	while (std::getline(read, input))
	{
		StringList_push_back(data, input);
	}
	read.close();
	return data;
}

void AdminSide::MapAddNode()
{
	std::string input;
	std::cout << "请输入新节点（如:text）：";
	std::getline(std::cin, input);
	auto data = ReadMapListTxt();
	while (data->next != nullptr)
	{
		data = data->next;
		if (data->data == input)
		{
			std::cout << "添加错误，该节点已存在" << std::endl;
			return;
		}
	}
	std::ofstream write;
	write.open("MapList.txt", std::ios_base::app);
	write << input << std::endl;
	write.close();
	std::cout << "添加成功" << std::endl;
}

void AdminSide::MapModifyNodeName()
{
	auto* data = new StringVector;
	[&data] {
		std::ifstream readList;
		readList.open("MapList.txt", std::ios_base::in);
		if (readList.is_open() == false)
		{
			std::cout << "查看失败    地图打开异常" << std::endl;
			return;
		}
		std::string input;
		std::cout << "*= ================================================  =*" << std::endl;
		std::cout << "                        地图节点                       " << std::endl;
		int number = 0;
		std::cout << "序号" << "\t" << "名称" << std::endl;

		while (std::getline(readList, input))
		{
			std::cout << number << "\t" << input << std::endl;
			StringVector_push_back(data, input);
			number++;
		}
		std::cout << "*= ================================================  =*" << std::endl;
		readList.close();
	}();

	std::string inputNumber;
	std::string inputName;
	std::cout << "请输入待修改的节点编号:";
	std::getline(std::cin, inputNumber);
	std::cout << "请输入新名称：:";
	std::getline(std::cin, inputName);
	int number;
	std::stringstream stream(inputNumber);
	stream >> number;

	if (number >= StringVector_size(data))
	{
		std::cout << "修改失败， 无此节点" << std::endl;
		return;
	}
	data->data[number] = inputName;

	std::ofstream write;
	write.open("MapList.txt", std::ios_base::out);
	for (int i = 0; i < StringVector_size(data); i++)
	{
		write << data->data[i] << std::endl;
	}
	write.close();
	std::cout << "修改成功" << std::endl;
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
