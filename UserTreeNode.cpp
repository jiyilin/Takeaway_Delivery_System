#include "UserTreeNode.h"
#include <fstream>

UserTreeNode *SortedUserListToBST(UserList *&lock)
{
	if (UserList_Length(lock) == 0)
	{
		return nullptr;
	}
	lock = lock->next;
	auto left = UserList_InitUserList();
	auto right = UserList_InitUserList();

	auto key = new UserTreeNode;
	key->data = UserList_gain_center(lock);

	auto search = lock;
	while (search != nullptr)
	{
		if (key == nullptr)
		{
			break;
		}
		if (search->data->GainUserID() > key->data->GainUserID())
		{
			auto process = new User(search->data->GainUserID(), search->data->GainUserPassword());
			UserList_push_back(right, *process);
		}
		else if (search->data->GainUserID() < key->data->GainUserID())
		{
			auto process = new User(search->data->GainUserID(), search->data->GainUserPassword());
			UserList_push_back(left, *process);
		}
		search = search->next;
	}

	key->left = SortedUserListToBST(left);
	key->right = SortedUserListToBST(right);
	return key;
}

bool SearchUserTreeNode(UserTreeNode *&lock, std::string eval, User *&key)
{
	if (lock == nullptr)
	{
		return false;
	}
	bool flag = false;
	if (lock->data->GainUserID() > eval)
	{
		flag = SearchUserTreeNode(lock->left, eval, key);
	}
	else if (lock->data->GainUserID() < eval)
	{
		flag = SearchUserTreeNode(lock->right, eval, key);
	}
	else
	{
		key = lock->data;
	}
	if (key == nullptr)
	{
		return false;
	}
	return true;
}

bool SearchUserTreeList(UserList *lock, std::string eval, User *&key)
{
	// while (lock->next != nullptr)
	//{
	//	lock = lock->next;
	//	if (lock->data->Gain_User_Id() == eval)
	//	{
	//		key = lock->data;
	//		return true;
	//	}
	// }
	// key = nullptr;
	// return false;

	auto data = SortedUserListToBST(lock);
	if (!SearchUserTreeNode(data, eval, key))
	{
		key = nullptr;
		return false;
	}
	return true;
}

UserList *GainUSerData()
{
	auto lock = UserList_InitUserList();
	if (!UserList_Read_Txt(lock))
	{
		std::cout << "用户数据异常，无法获取用户数据" << std::endl;
		return nullptr;
	}
	// auto key = SortedUserListToBST(lock);
	return lock;
}

bool UserDataFlushed(std::string flag)
{
	auto *lock = UserList_InitUserList();
	if (!UserList_Read_Txt(lock))
	{
		return false;
	}

	std::ofstream write;
	write.open("./data/UsersData.txt", std::ios_base::out);
	while (lock->next != nullptr)
	{
		lock = lock->next;
		if (lock->data->GainUserID() != flag)
		{
			write << lock->data->GainUserID() << " " << lock->data->GainUserPassword() << std::endl;
		}
	}
	write.close();
	return true;
}

bool UserLoad(std::string id, std::string password, User *&key)
{
	key = nullptr;
	auto data = GainUSerData();
	if (!SearchUserTreeList(data, id, key))
	{
		key = nullptr;
		return false;
	}
	else
	{
		if (key->GainUserPassword() == password && UserDataFlushed(key->GainUserID()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
