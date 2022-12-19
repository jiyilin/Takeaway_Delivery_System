#include "Map.h"
#include<iostream>
#include<fstream>

bool Map::ReadMapList()
{
	std::ifstream read;
	read.open("MapList.txt", std::ios_base::in);
	if (read.is_open() == false)
	{
		std::cout << "ERROR    ��ͼ�ļ���ȡ����" << std::endl;
		return false;
	}
	std::string input;
	while (std::getline(read,input))
	{
		this->MapList.push_back(input);
	}
	return true;
}

void Map::GainRoute()
{

}

void Map::Print_Route()
{
	auto search = this->key.begin();
	int number = 1;
	std::cout << "*= ================================================  =*" << std::endl;
	std::cout << "                          ·������                     " << std::endl;
	while (search != key.end())
	{
		std::cout << number << ".  " << *search << std::endl;
		search++;
		number++;
	}
	std::cout << "*= ================================================  =*" << std::endl;
}

bool Map::SEARCH_MAP(std::string lock)
{
	auto search = this->MapList.begin();
	while (search!=this->MapList.end())
	{
		if (*search == lock)
		{
			return true;
		}
		search++;
	}
	return false;
}
