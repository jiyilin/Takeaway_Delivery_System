#include "Kernel.h"
#include<iostream>
#include<string>


int Kernel::GainMenuChoose(int max,bool isZero)
{
	std::cout << "����������Ҫ�Ĺ��ܴ���:";
	std::string input;
	int key;
	while (true)
	{
		std::getline(std::cin, input);
		if (input.length()!=1 || input[0]<'0' || input[0]>'9')
		{
			std::cout << "����������������룺";
			continue;
		}
		key = input[0] - '0';
		if (isZero == true && ( key < 0  || key > max ))
		{
			std::cout << "����������������룺";
		}
		else if(isZero == false && (key < 1 || key > max))
		{
			std::cout << "����������������룺";
		}
		else
		{
			break;
		}
	}
	return key;
}
