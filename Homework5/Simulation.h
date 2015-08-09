/*
 * Simulation.h
 *
 *  Created on: 22.01.2015 г.
 *      Author: stoian
 */

#pragma once
struct Simulation
{
	size_t liters;
	size_t time;
	Simulation(size_t liters , size_t time)
	{
		this-> liters= liters;
		this-> time= time;
	}
};
