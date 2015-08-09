#include <iostream>
#include "Queue.h"
#include "Market.h"
#include "List.h"

int main()
{
	List<int> list;
	for (size_t i = 0; i < 10; ++i)
	{
		list.addFront(i);
	}
	for (size_t i = 0; i < 10; ++i)
	{
		list.addLast(i);
	}

	for (size_t i = 0; i < 20; ++i)
	{
		std::cout << list[i];
	}

	std::cout << std::endl;
	for (size_t i = 0; i < 5; ++i)
	{
		list.removeFirst();
	}
	for (size_t i = 0; i < 5; ++i)
	{
		list.removeLast();
	}
	for (size_t i = 0; i < list.getSize(); ++i)
	{
		std::cout << list[i];
	}

	std::cout << "\n//////////////////////////////////////////////////////\n";
	Market myMarket(3);
	std::cout << myMarket.getMarketState().numberOfCashDesk << "     \n"
		<< myMarket.getMarketState().numberOfCashDesk << "         \n"
		<< myMarket.getMarketState().numberOfClientsAtExpressCashDeck << std::endl;

	std::cout << "\n//////////////////////////////////////////////////////\n";
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);

	for (size_t i = 0; i < q.getSize(); ++i)
	{
		std::cout << q[i] << std::endl;
	}

	std::cout << "\n//////////////////////////////////////////////////////\n";


	Market myMarket2(5);
	
	Client c1,c2,c3;
	c1.creditCard = false;
	c1.creditCard = 1;
	c1.numberOfGoods = 1;
	c2.creditCard = false;
	c2.creditCard = 2;
	c2.numberOfGoods = 2;
	c3.creditCard = false;
	c3.creditCard = 3;
	c3.numberOfGoods = 1;
	Client clients[] = {c1,c2,c3};
	myMarket2.AddClient(clients, 3);
	MarketState st = myMarket2.getMarketState();
	std::cout << st.numberOfCashDesk << "     \n"
		<< st.numberOfClientsAtCashDecsk << "\n"
		<< st.numberOfClientsAtExpressCashDeck << std::endl;
	//std::cout << myMarket2.getnumberOfGoods();

	std::cout << "\n//////////////////////////////////////////////////////\n";
	Queue<int> w;
	w.enqueue(1);
	Queue<int>* ww = &w;
	std::cout << &w << "        " << ww<<std::endl;
	std::cout << ww->dequeue() << std::endl;

	std::cout << "\n//////////////////////////////////////////////////////\n";

	Market myMarket3(3);
	c1.numberOfGoods = 5;
	c2.numberOfGoods = 4;
	c3.numberOfGoods = 6;
	Client c4;
	c4.ID = 43;
	c4.creditCard = true;
	c4.numberOfGoods = 5;
	Client c5;
	c5.creditCard = false;
	c5.ID = 32;
	c5.numberOfGoods = 4;
	Client c6;
	c6.creditCard = false;
	c6.ID = 41;
	c6.numberOfGoods = 7;
	Client  clients2[] = { c1,c2,c3};
	myMarket3.AddClient(clients2, 3);
	Client clients3[] = { c4 };
	myMarket3.AddClient(clients3, 1);
	MarketState ms = myMarket3.getMarketState();
	std::cout << ms.numberOfCashDesk << std::endl;
	Client clients4[] = { c5, c6 };
	myMarket3.AddClient(clients4, 2);
	MarketState ms2 = myMarket3.getMarketState();
	std::cout << ms2.numberOfCashDesk << std::endl;
	std::cout << myMarket3.getnumberOfGoods();
	return 0;
}
