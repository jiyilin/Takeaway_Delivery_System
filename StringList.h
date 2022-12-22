#pragma once
#ifndef STRINGLIST_H
#define STRINGLIST_H

#include<string>

using StringList = struct StringList
{
	std::string data;
	StringList* next = nullptr;
};

void StringList_push_back(StringList* lock, std::string eval);
std::string* StringList_pop_back(StringList* lock);
std::string* StringList_pop_front(StringList* lock);
void StringList_push_front(StringList* lock, std::string eval);
StringList* StringList_init();
int StringList_length(StringList* lock);
bool StringList_empty(StringList* lock);
bool StringList_search(StringList* lock, std::string eval);
std::string StringList_Gain_center(StringList* lock);

#endif // !STRINGLIST_H