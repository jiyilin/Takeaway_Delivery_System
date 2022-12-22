#include "StringList.h"

void StringList_push_back(StringList* lock, std::string eval)
{
	auto search = lock;
	while (search->next != nullptr)
	{
		search = search->next;
	}
	auto key = new StringList;
	key->next = nullptr;
	key->data = eval;
	search->next = key;
}

std::string* StringList_pop_back(StringList* lock)
{
	if (StringList_empty(lock) == true)
	{
		return nullptr;
	}
	auto search = lock;
	while (search->next->next != nullptr)
	{
		search = search->next;
	}
	auto key = search->next;
	search->next = nullptr;
	return &key->data;
}

std::string* StringList_pop_front(StringList* lock)
{
	if (StringList_empty(lock) == true)
	{
		return nullptr;
	}
	auto key = lock->next;
	lock->next = lock->next->next;
	return &key->data;
}

void StringList_push_front(StringList* lock, std::string eval)
{
	auto key = new StringList;
	key->next = nullptr;
	key->data = eval;
	key->next = lock->next;
	lock->next = key;
}

StringList* StringList_init()
{
	auto key = new StringList;
	key->next = nullptr;
	return key;
}

int StringList_length(StringList* lock)
{
	auto search = lock;
	int key = 0;
	while (search->next != nullptr)
	{
		search = search->next;
		key++;
	}
	return key;
}

bool StringList_empty(StringList* lock)
{
	if (lock->next == nullptr)
	{
		return true;
	}
	return false;
}

bool StringList_search(StringList* lock, std::string eval)
{
	auto search = lock;
	while (search->next != nullptr)
	{
		search = search->next;
		if (search->data == eval)
		{
			return true;
		}
	}
	return false;
}

std::string StringList_Gain_center(StringList* lock)
{
	int flag = StringList_length(lock) / 2;
	auto search = lock;
	while (flag != 0)
	{
		search = search->next;
		flag--;
	}
	return search->data;
}

