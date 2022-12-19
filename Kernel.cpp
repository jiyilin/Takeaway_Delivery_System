#include "Kernel.h"
#include <iostream>
#include <string>

int Kernel::GainMenuChoose(int max, bool isZero)
{
	std::cout << "请输入您需要的功能代号:";
	std::string input;
	int key;
	while (true)
	{
		std::getline(std::cin, input);
		if (input.length() != 1 || input[0] < '0' || input[0] > '9')
		{
			std::cout << "输入错误，请重新输入：";
			continue;
		}
		key = input[0] - '0';
		if (isZero == true && (key < 0 || key > max))
		{
			std::cout << "输入错误，请重新输入：";
		}
		else if (isZero == false && (key < 1 || key > max))
		{
			std::cout << "输入错误，请重新输入：";
		}
		else
		{
			break;
		}
	}
	return key;
}
