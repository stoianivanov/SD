#pragma once 
#include "ClientState.h"
#include "MarketState.h"
#include "List.h"
#include "Queue.h"
class Market
{
private:
	size_t maxCashDecks; // максималния брой на каси, който могат да бъдат отворение
	List<Queue<Client>> queueClient; // списък от опашки
	MarketState marketState;
	//// броя на касите които са отворили в момента
	//// броя на клиентите на всяка каса в този момент
	////експресна каса

	Queue<Client> expressCase;//експресна каса
	
	/*
		ClientState clientState;
		//// номер на каса
		//// позиция в опашката на касата
		////клиент
	*/
	

public:
	Market(int NumberOfAllCashDecks); // максимални брой каси които може да бъдат отворени в магазина (без експресната)
	void AddClient(Client * clients, int number); // добавяме number клиенти в магазина
	MarketState getMarketState(); // връща състоянието на магазина
	ClientState getClientState(int ID); // връща състоянието на клиента

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

