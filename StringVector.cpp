#include "StringVector.h"
#include<sstream>

constexpr auto StringVector_INIT = 20;

int StringVector_size(StringVector* lock)
{
	int key = lock->length;
	return key;
}

bool StringVector_empty(StringVector* lock)
{
	if ( lock->length != 0)
	{
		return true;
	}
	return false;
}

void GainMapHistoryString(std::string lock, int& from, int& to, double& distance)
{
	std::string fromString;
	std::string toString;
	std::string distanceString;
	int flag = 0;
	for (int i = 0; i < lock.size(); i++)
	{
		if (lock[i] == ' ')
		{
			flag++;
		}
		if (flag == 0 && lock[i] != ' ')
		{
			fromString.push_back(lock[i]);
		}
		else if (flag == 1 && lock[i] != ' ')
		{
			toString.push_back(lock[i]);
		}
		else if (flag == 2 && lock[i] != ' ')
		{
			distanceString.push_back(lock[i]);
		}
	}
	std::stringstream streamFrom(fromString);
	std::stringstream streamTo(toString);
	std::stringstream streamDistance(distanceString);
	streamFrom >> from;
	streamTo >> to;
	streamDistance >> distance;
}

void StringVector_sort(StringVector*& lock)
{
}

void StringVector_expansion(StringVector*& lock)
{
	auto key = new StringVector(lock->maxSize + 10);
	key->length = 0;
	key->maxSize = lock->maxSize + 10;
	for (int i = 0; i < lock->length; i++)
	{
		StringVector_push_back(key, lock->data[i]);
	}
	lock = key;
}

void StringVector_push_back(StringVector*& lock, std::string eval)
{
	if (lock->length == lock->maxSize)
	{
		StringVector_expansion(lock);
	}
	lock->data[lock->length] = eval;
	lock->length++;
}

bool StringVector_pop_bakc(StringVector*& lock)
{
	if (lock->length != 0)
	{
		lock->length--;
		return true;
	}
	return false;
}

StringVector::StringVector()
{
	this->data = new std::string[StringVector_INIT];
	this->maxSize = StringVector_INIT;
}

StringVector::StringVector(int eval)
{
	this->data = new std::string[eval];
	this->maxSize = eval;
}