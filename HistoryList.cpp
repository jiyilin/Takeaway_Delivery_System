#include "HistoryList.h"

void HistoryList_push_back(HistoryList* lock, std::string eval)
{
	auto end = lock;
	while (end->next != nullptr)
	{
		end = end->next;
	}

	auto node = new HistoryList;
	node->data = eval;
	node->next = nullptr;

	end->next = node;
}

bool HistoryList_Empty(HistoryList* lock)
{
	if (lock->next == nullptr)
	{
		return true;
	}
	return false;
}

HistoryList* HistoryList_Init()
{
	auto head = new HistoryList;
	head->next = nullptr;
	return head;
}

std::string HistoryList_pop_Back(HistoryList* lock)
{
	if (HistoryList_Empty(lock))
	{
		return "00000";
	}
	auto end = lock;
	while (end->next->next != nullptr)
	{
		end = end->next;
	}
	std::string key = end->next->data;
	end->next = nullptr;
	return key;
}
