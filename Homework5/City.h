/*
 * City.h
 *
 *  Created on: 22.01.2015 г.
 *      Author: stoian
 */

#pragma once
#include "Matrix.h"
#include <list>
#include "Simulation.h"

class City
{
public:
	City( Matrix& height,Matrix& junction,size_t carrinCapasity);
	void simulation();

private:
	void drainInside( double liters,bool* street, size_t size, size_t x, size_t y);
	void drain(Simulation&);
	void startSimulation(std::list<Simulation>&);
private:
	double carringCapasity;
	Matrix height;
	Matrix junction;
};
