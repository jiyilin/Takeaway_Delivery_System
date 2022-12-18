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
		std::cout << "�û�ע��" << std::endl;
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

void AdminSide::AdminSideStart()
{
	system("cls");
	while (this->AdminSideMenu())
	{
		system("pause");
		system("cls");
	}
	std::cout << "���Ѱ�ȫ�˳�����Ա�ˣ���ӭ�´�ʹ��" << std::endl;
}
