#pragma once
#ifndef STRINGVECTOR_H
#define STRINGVECTOR_H

#include <string>

using StringVector = struct StringVector
{
	std::string* data;
	int length = 0;
	int maxSize;
	StringVector();
	StringVector(int eval);
};

int StringVector_size(StringVector* lock);
bool StringVector_empty(StringVector* lock);
void StringVector_sort(StringVector*& lock);
void StringVector_push_back(StringVector*& lock, std::string eval);
bool StringVector_pop_bakc(StringVector*& lock);
void GainMapHistoryString(std::string lock, int& from, int& to, double& distance);

#endif // !STRINGVECTOR_H

