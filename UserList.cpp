#include "UserList.h"
#include <fstream>

void UserList_push_back(UserList*& lock, User eval)
{
	auto end = lock;
	while (end->next != nullptr)
	{
		end = end->next;
	}

	auto nodeData = new User(eval.GainUserID(),eval.GainUserPassword());
	auto node = new UserList;
	node->data = nodeData;
	node->next = nullptr;

	end->next = node;
}

void UserList_push_front(UserList*& lock, User eval)
{
	auto nodeData = new User(eval.GainUserID(), eval.GainUserPassword());
	auto node = new UserList;
	node->data = nodeData;
	node->next = lock->next;

	lock->next = node;
}

User* UserList_pop_back(UserList*& lock)
{
	if (UserList_Empty(lock))
	{
		return nullptr;
	}
	auto end = lock;
	while (end->next->next != nullptr)
	{
		end = end->next;
	}
	auto key = end->next->data;
	end->next = nullptr;
	return key;
}

User* UserList_pop_front(UserList*& lock)
{
	auto key = lock->data;
	lock = lock->next;
	lock->data = nullptr;
	return key;
}

bool UserList_Empty(UserList* lock)
{
	if (lock->next == nullptr)
	{
		return true;
	}
	return false;
}

int UserList_Length(UserList* lock)
{
	int key = 0;
	auto search = lock;
	while (search->next != nullptr)
	{
		search = search->next;
		key++;
	}
	return key;
}

User* UserList_gain_center(UserList* lock)
{
	int flag = UserList_Length(lock) / 2;
	auto search = lock;
	while (flag != 0)
	{
		search = search->next;
		flag--;
	}
	return search->data;
}

// User* UserList_Split(UserList* lock, UserList*& left, UserList*& right)
//{
//	UserList_sort(lock);
//	auto flag = UserList_Length(lock);
//	int i = 0;
//	auto search = lock;
//	while (search->next!=nullptr)
//	{
//		search = search->next;
//		i++;
//		if (i<flag)
//		{
//			UserList_push_back(left, *(search->data));
//		}
//		else
//		{
//			UserList_push_back(right, *(search->data));
//		}
//	}
//	return UserList_gain_center(lock);
// }

UserList* UserList_InitUserList()
{
	auto head = new UserList;
	head->next = nullptr;
	return head;
}

void UserList_sort(UserList*& lock)
{
	User* process;
	auto search = lock;
	auto flag = search;
	while (search->next != nullptr)
	{
		search = search->next;
		flag = search;
		while (flag != nullptr)
		{
			flag = flag->next;
			if (flag->data->GainUserID() < search->data->GainUserID())
			{
				process = search->data;
				search->data = flag->data;
				flag->data = process;
			}
		}
	}
}

std::string UserList_Gain_END_ID(UserList* data)
{
	if (UserList_Empty(data))
	{
		return "0000";
	}
	auto search = data;
	while (search->next != nullptr)
	{
		search = search->next;
	}
	return search->data->GainUserID();
}

bool UserList_Read_Txt(UserList*& lock)
{
	std::ifstream read;
	read.open("./data/UsersData.txt", std::ios_base::in);
	if (read.is_open() == false)
	{
		std::cout << "���ݿ��쳣���޷���ȡ�û�����" << std::endl;
		return false;
	}
	std::string id;
	std::string password;
	while (true)
	{
		if (read.eof())
		{
			break;
		}
		read >> id >>password;
		User process(id, password);
		if (process.GainUserID() != UserList_Gain_END_ID(lock))
		{
			UserList_push_back(lock, process);
		}
	}
	read.close();
	return true;
}
