#include "AdminSide.h"
#include<iostream>
#include<fstream>
#include<string>
#include"UserTreeNode.h"

constexpr auto AdministratorID = "���ݴ�ѧ����ѧԺ";
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
	std::cout << "|| *******     ��ӭʹ����������ϵͳ�����     ****** ||" << std::endl;
	std::cout << "|| *              1. �û�����ȫ��                  * ||" << std::endl;
	std::cout << "|| *              2. �û�ע��                      * ||" << std::endl;
	std::cout << "|| *              3. ��ͼ�鿴                      * ||" << std::endl;
	std::cout << "|| *              4. ��ͼ�޸�                      * ||" << std::endl;
	std::cout << "|| *              0. �˳�                          * ||" << std::endl;
	std::cout << "|| *******                                    ****** ||" << std::endl;
	std::cout << "*= ================================================  =*" << std::endl;
}

bool AdminSide::AdminSidePro(int button)
{
	switch (button)
	{
	case 1:
		std::cout << "�û�����ȫ��" << std::endl;
		break;
	case 2:
		this->UserLogsOff();
		break;
	case 3:
		std::cout << "��ͼ�鿴" << std::endl;
		break;
	case 4:
		std::cout << "��ͼ�޸�" << std::endl;
		break;
	default:
		return false;
	}
	return true;
}

void AdminSide::UserLogsOff()
{
	std::string id;
	std::cout << "�������ɾ�����û��˺ţ�";
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
		std::cout << "ɾ���ɹ�" << std::endl;
	}
	else
	{
		std::cout << "ɾ��ʧ��   δ�ҵ����û�" << std::endl;
	}
}

bool AdminSide::AdminSideLoad()
{
	std::string id;
	std::string passowrd;
	std::cout << "���������Ա�˺ţ�";
	std::getline(std::cin, id);
	std::cout << "���������Ա���룺";
	std::getline(std::cin, passowrd);
	if (id != AdministratorID || passowrd != AdministratorPassword)
	{
		return false;
	}
	return true;
}

void AdminSide::AdminSideStart()
{
	if (this->AdminSideLoad() == false)
	{
		std::cout << "��¼ʧ��   ����Ա�˺Ż��������" << std::endl;
		return;
	}
	system("cls");
	while (this->AdminSideMenu())
	{
		system("pause");
		system("cls");
	}
	std::cout << "���Ѱ�ȫ�˳�����Ա�ˣ���ӭ�´�ʹ��" << std::endl;
}
