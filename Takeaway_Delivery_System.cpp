// Takeaway_Delivery_System.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "TakeawayDeliverySystem.h"

int main()
{
	TakeawayDeliverySystem Demo{};
	if (Demo.EngineDetection())
	{
		Demo.EngineStarts();
	}
	return 0;
}