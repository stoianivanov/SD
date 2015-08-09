#pragma once
#include "Client.h"
struct ClientState
{
	int CashDeskPosition; // номер на каса
	int QueuePosition; // позиция в опашката на касата
	Client * client;
};