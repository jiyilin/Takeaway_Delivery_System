#pragma once

#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <list>

class Map
{
private:
	std::vector<std::string> MapList;
	std::list<std::string> key;

public:
	bool SEARCH_MAP(std::string lock);
	bool ReadMapList();
	void GainRoute(std::string From, std::string To);
	void Print_Route();
};

#endif // !MAP_H
