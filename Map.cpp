#include "Map.h"
#include<iostream>
#include<fstream>

bool Map::ReadMapList()
{
	std::ifstream read;
	read.open("MapList.txt", std::ios_base::in);
	if (read.is_open() == false)
	{
		std::cout << "ERROR    地图文件读取错误" << std::endl;
		return false;
	}
	std::string input;
	while (std::getline(read,input))
	{
		this->MapList.push_back(input);
	}
	return true;
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
