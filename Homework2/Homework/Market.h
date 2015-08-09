#pragma once 
#include "ClientState.h"
#include "MarketState.h"
#include "List.h"
#include "Queue.h"
class Market
{
private:
	size_t maxCashDecks; // ����������� ���� �� ����, ����� ����� �� ����� ���������
	List<Queue<Client>> queueClient; // ������ �� ������
	MarketState marketState;
	//// ���� �� ������ ����� �� �������� � �������
	//// ���� �� ��������� �� ����� ���� � ���� ������
	////��������� ����

	Queue<Client> expressCase;//��������� ����
	
	/*
		ClientState clientState;
		//// ����� �� ����
		//// ������� � �������� �� ������
		////������
	*/
	

public:
	Market(int NumberOfAllCashDecks); // ���������� ���� ���� ����� ���� �� ����� �������� � �������� (��� �����������)
	void AddClient(Client * clients, int number); // �������� number ������� � ��������
	MarketState getMarketState(); // ����� ����������� �� ��������
	ClientState getClientState(int ID); // ����� ����������� �� �������

	int getnumberOfGoods();
private:
	void makeExpressCase(Client* clients, int number);
	bool openNewCase(int & maxClientCase);
	int  maxQueue();
	int* closeCase();
	int minQueue();
	void shuffleClient(Queue<Client> q);
	void cutQueue(Queue<Client> *bufferQ, Queue<Client>& p);
	void payBil( );
	void Add(Client* clients, int number);
	void CaseWitnN(bool&);
	void checkCase(bool&);
	void caseWithFewClient(bool&);
};

