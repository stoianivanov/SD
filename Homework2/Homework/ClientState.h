#pragma once
#include "Client.h"
struct ClientState
{
	int CashDeskPosition; // ����� �� ����
	int QueuePosition; // ������� � �������� �� ������
	Client * client;
};