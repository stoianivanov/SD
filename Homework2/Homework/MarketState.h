#pragma once 

struct MarketState
{
	int numberOfCashDesk; // броя на касите които са отворили в момента
	int* numberOfClientsAtCashDecsk; // броя на клиентите на всяка каса в този момент
	int numberOfClientsAtExpressCashDeck;
};