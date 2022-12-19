#pragma once

#ifndef TAKEAWAYDELIVERYSYSTEM_H
#define TAKEAWAYDELIVERYSYSTEM_H

#include "Kernel.h"
#include "Client.h"
#include "AdminSide.h"

class TakeawayDeliverySystem : private Kernel
{
private:
	ClientSystem client;
	AdminSide adminSide;
	bool TakeawayDeliverySystemMenu();
	void TakeawayDeliverySystemUI();
	bool TakeawayDeliverySystemPro(int button);

public:
	bool EngineDetection();
	void EngineStarts();
};

#endif // !TAKEAWAYDELIVERYSYSTEM_H
