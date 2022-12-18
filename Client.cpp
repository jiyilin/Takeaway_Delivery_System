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
	std::cout << "|| *******     ��ӭʹ����������ϵͳ�ͻ���     ****** ||" << std::endl;
	std::cout << "|| *              1. ��¼                          * ||" << std::endl;
	std::cout << "|| *              2. ע��                          * ||" << std::endl;
	std::cout << "|| *              0. �˳�                          * ||" << std::endl;
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

void ClientSystem::RegisteredUsers()
{
	std::string idInput;
	std::string passwordInput;
	std::cout << "�������˺ţ�";
	std::getline(std::cin, idInput);
	std::cout << "����������(����Ӧ����5λ��С��16λ)��";
	std::getline(std::cin, passwordInput);
	std::string process;

	std::ifstream read;
	read.open("./data/UserData.txt", std::ios_base::in);
	while (std::getline(read,process))
	{
		if (std::strstr(process.c_str(),idInput.c_str()) != nullptr)
		{
			std::cout << "ע��ʧ��!!!   ���û��ѱ�ע��" << std::endl;
			read.close();
			return;
		}
	}
	read.close();

	std::ofstream write;
	write.open("./data/UserData.txt", std::ios_base::app);
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
	std::cout << "���Ѱ�ȫ�˳��ͻ��ˣ���ӭ�´�ʹ��" << std::endl;
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
	std::cout << "|| *******     ��ӭʹ����������ϵͳ�ͻ���     ****** ||" << std::endl;
	std::cout << "|| *              1. Ѱ����·                      * ||" << std::endl;
	std::cout << "|| *              2. ��ʷ��¼                      * ||" << std::endl;
	std::cout << "|| *              3. �޸�����                      * ||" << std::endl;
	std::cout << "|| *              4. �˺�ע��                      * ||" << std::endl;
	std::cout << "|| *              0. �˳�                          * ||" << std::endl;
	std::cout << "|| *******                                    ****** ||" << std::endl;
	std::cout << "*= ================================================  =*" << std::endl;
}

bool Client::ClientPro(int button)
{
	switch (button)
	{
	case 1:
		std::cout << "Ѱ����·" << std::endl;
		break;
	case 2:
		std::cout << "��ʷ��¼" << std::endl;
		break;
	case 3:
		std::cout << "�޸�����" << std::endl;
		break;
	case 4:
		std::cout << "�˺�ע��" << std::endl;
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
		std::cout << "��¼ʧ��!!!   �˺Ż��������" << std::endl;
		return;
	}
	while (this->ClientMenu())
	{
		system("pause");
		system("cls");
	}
}
