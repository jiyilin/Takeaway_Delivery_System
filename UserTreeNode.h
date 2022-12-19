#pragma once

#ifndef USERTREENODE_H
#define USERTREENODE_H

#include"UserList.h"

using UserTreeNode = struct UserTreeNode
{
	User* data;
	UserTreeNode* left;
	UserTreeNode* right;
	UserTreeNode() : data(nullptr), left(nullptr), right(nullptr) {};
};

UserTreeNode* SortedUserListToBST(UserList*& lock);
bool SearchUserTreeNode(UserTreeNode*& lock, std::string eval, User*& key);
UserList* GainUSerData();
bool UserLoad(std::string id, std::string password, User*& key);
#endif // !USERTREENODE_H