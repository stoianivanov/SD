#include "Market.h"

Market::Market(int NumberofAllCashDecks)
{
	this->maxCashDecks = NumberofAllCashDecks;
	Queue<Client> newQueue;
	queueClient.addLast(newQueue);

}
MarketState Market::getMarketState()
{
	const size_t size = queueClient.getSize();
	MarketState newMarketState;
	newMarketState.numberOfCashDesk = size; // броя на касите които са отворили в момента
	newMarketState.numberOfClientsAtExpressCashDeck = expressCase.getSize();//Броя на клиентите на експресната каса

	// броя на клиентите на всяка каса в този момент
	newMarketState.numberOfClientsAtCashDecsk = new int[size];
	for (size_t i = 0; i < queueClient.getSize(); ++i)
	{
		newMarketState.numberOfClientsAtCashDecsk[i] = queueClient[i].getSize();
	}
	return newMarketState;


}

ClientState Market::getClientState(int ID)
{
	ClientState p;
	p.CashDeskPosition = -1;
	p.QueuePosition = -1;
	p.client = nullptr;

	for (size_t i = 0; i < queueClient.getSize(); ++i)
	{
		for (size_t j = 0; j < queueClient[i].getSize(); ++j)
		{
			if (queueClient[i].at(j).ID == ID)
			{
				p.CashDeskPosition = i;
				p.QueuePosition = j;
				p.client->ID = queueClient[i].at(j).ID;
				p.client->numberOfGoods = queueClient[i].at(j).numberOfGoods;
				p.client->creditCard = queueClient[i].at(j).creditCard;
			}
		}
	}

	for (size_t i = 0; i < expressCase.getSize(); ++i)
	{
		if (expressCase[i].ID == ID)
		{
			p.CashDeskPosition = 0;
			p.QueuePosition = i;
			p.client->ID = expressCase[i].ID;
			p.client->numberOfGoods = expressCase[i].numberOfGoods;
			p.client->creditCard = expressCase[i].creditCard;
		}
	}


	return p;
}


// ако клиента е с по малко от 3 покупки отива в експресната каса
void Market::makeExpressCase(Client* clients, int number)
{
	for (size_t i = 0; i < number; ++i)
	{
		int numberOfGoods = clients[i].numberOfGoods; // брой на покупките на клиента 

		if (numberOfGoods <= 3 && expressCase.getSize() <= 2 * maxCashDecks&&numberOfGoods>0)
		{
			expressCase.enqueue(clients[i]);
		}
	}
}
void Market::Add(Client* clients, int number)
{
	for (size_t i = 0; i < number; ++i)
	{
		int numberOfGoods = clients[i].numberOfGoods; // брой на покупките на клиента 

		if (numberOfGoods > 3)
		{
			queueClient[0].enqueue(clients[i]);
		}
	}
}

// ако има над Н клиента 
void Market::CaseWitnN( bool& event)
{
	int pos = maxQueue();
	if (openNewCase(pos))
	{
		Queue<Client> q;
		size_t size = queueClient[pos].getSize();
		Queue<Client>* maxQ = &queueClient[pos];
		for (size_t i = 0; i < size / 2; ++i)
		{
			q.enqueue(maxQ->dequeue());
		}
		queueClient.addLast(q);
		event = false;
	}

}

//проверя дали има разлика между касите 
void Market::checkCase( bool& event){
	size_t arrSize = queueClient.getSize();
	Queue<Client>* clientQ = new Queue<Client>[arrSize];

	for (size_t i = 0; i < arrSize - 1; ++i)
	{
		for (size_t j = 1; j < arrSize; ++j)
		{
			int n = clientQ[i].getSize() - clientQ[j].getSize();
			if (n > maxCashDecks / 8)
			{
				//касата i e  по голяма от нея трябва да се прехвърлят клиенти
				Queue<Client> *bufferQ = &queueClient[i];
				Queue<Client> p;
				cutQueue(bufferQ, p);
				//преразпределяна на клиентите 
				shuffleClient(p);
				event = false;
			}
			if (((-1)*n) > maxCashDecks / 8)
			{
				//касата i e  по голяма от нея трябва да се прехвърлят клиенти
				Queue<Client> *bufferQ = &queueClient[j];
				Queue<Client> p;
				cutQueue(bufferQ, p);
				//преразпределяна на клиентите 
				shuffleClient(p);
			}
		}
		
	}
	delete[] clientQ;
}
void Market::caseWithFewClient( bool& event)
{
	int * arr = closeCase();
	Queue<Client> q;
	for (size_t i = 0; arr[i] != -1; ++i)
	{

		int idx = arr[i];
		Queue<Client> * buffer;
		buffer = &queueClient.removeAt(idx);
		while (buffer->isEmpty())
		{
			q.enqueue(buffer->dequeue());
			
		}
		event = false;
		// пълня опашка с клиенти който са били на затворена каса	
	}
	// клиентие който си нямат каса трябва да се пренаредят към другите каси
	shuffleClient(q);
}
void Market::AddClient(Client * clients, int number)
{
	
	// ако клиента е с по малко от 3 покупки отива в експресната каса
	makeExpressCase(clients, number);

	// добавяне на клиенти с повече покупки 
	Add(clients, number);
	bool event = true;
	//затваряне на каса
	if (event)
	{
		caseWithFewClient(event);
	}
	if (event)
	{
		checkCase(event);
	}
	if (event)
	{
		CaseWitnN(event);
		//ако има над  N клиента
	}

	//Плащане 
	payBil();
}

bool Market::openNewCase(int& max)
{
		if (queueClient[max].getSize()>maxCashDecks)
		{
			return true;
		}
		return false;
	
}
int  Market::maxQueue()
{
	int maxInd = 0;
	int maxSize = queueClient[maxInd].getSize();
	for (size_t i = 1; i < queueClient.getSize(); ++i)
	{
	
		if (maxSize < queueClient[i].getSize())
		{
			maxInd = i;
			maxSize = queueClient[maxInd].getSize();
		}
	}

	return maxInd;
}
int* Market::closeCase()
{
	int* arr = new int[maxCashDecks];
	size_t j = 0;
	for (size_t i = 0; i < queueClient.getSize(); ++i)
	{
		if (queueClient[i].getSize() < maxCashDecks / 10)
		{
			arr[j] = i;
			++j;
		}
	}
	
		while (j < maxCashDecks)
		{
			arr[j] = -1;
			++j;
		}

		return arr;
}

int Market::minQueue()
{
	size_t minInd = 0;
	for (size_t i = 1; i < queueClient.getSize(); ++i)
	{
		if (queueClient[minInd].getSize() < queueClient[i].getSize())
		{
			minInd = i;
		}
	}
	
	return minInd;
}
void Market::shuffleClient(Queue<Client> q)
{
	for (size_t i = 0; i < q.getSize(); ++i)
	{
		size_t index = minQueue();
		queueClient[i].enqueue(q.dequeue());
	}
}
void Market::cutQueue(Queue<Client> *bufferQ, Queue<Client>& p)
{
	
	size_t sizeI = (bufferQ->getSize()) / 2;
	while (sizeI >= 0)
	{
		p.enqueue(bufferQ->dequeue());
		--sizeI;
	}
}
void Market::payBil()
{
	
	size_t size = queueClient.getSize();

	Queue<Client>* arr = new Queue<Client>[size];
	for (size_t i = 0; i < size; ++i)
	{
		if (!arr[i].isEmpty())
		{
			arr[i].dequeue();
		}
				
	}
}
int Market::getnumberOfGoods()
{
	return queueClient[0].getSize();
}