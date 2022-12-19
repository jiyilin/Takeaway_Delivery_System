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
	std::cout << "�������˺ţ�";
	std::getline(std::cin, idInput);
	std::cout << "����������(����Ӧ����5λ��С��16λ)��";
	std::getline(std::cin, passwordInput);
	std::string process;

	std::ifstream read;
	read.open("./data/UsersData.txt", std::ios_base::in);
	while (std::getline(read,process))
	{
		GainID(process);
		if (process == idInput)
		{
			std::cout << "ע��ʧ��!!!   ���û��ѱ�ע��" << std::endl;
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
		this->ChangeUserPassword();
		break;
	case 4:
		std::cout << "�˺�ע���ɹ�" << std::endl;
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
	std::cout << "�������˺ţ�";
	std::getline(std::cin, id);
	std::cout << "���������룺";
	std::getline(std::cin, password);
	if (id.length() == 0 || password.length() == 0)
	{
		std::cout << "��¼ʧ��    �˺����벻��Ϊ��" << std::endl;
	}
	else if (UserLoad(id,password,this->useNow))
	{
		std::cout << "��¼�ɹ�" << std::endl;
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
	std::cout << "������ԭ���룺";
	std::getline(std::cin, oldPassword);
	if (oldPassword != this->useNow->GainUserPassword())
	{
		std::cout << "�����޸�ʧ��!!!   �����������" << std::endl;
		return;
	}
	std::cout << "�����������룺";
	std::getline(std::cin, newPassowrd);
	if (oldPassword == newPassowrd)
	{
		std::cout << "�����޸�ʧ��!!!   ԭ������������һ��" << std::endl;
		return;
	}
	this->useNow->SetUserPassword(newPassowrd);
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

Client::~Client() = default;
