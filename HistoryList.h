#pragma once

#ifndef HISTORYLIST_H
#define HISTORYLIST_H

#include <string>

using HistoryList = struct HistoryList
{
	std::string data;
	HistoryList *next = nullptr;
};

void HistoryList_push_back(HistoryList *lock, std::string eval);
bool HistoryList_Empty(HistoryList *lock);
HistoryList *HistoryList_Init();
std::string HistoryList_pop_Back(HistoryList *lock);

#endif // !HISTORYLIST_H
