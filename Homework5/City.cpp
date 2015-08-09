/*
 * City.cpp
 *
 *  Created on: 22.01.2015 г.
 *      Author: stoian
 */

#include "City.h"

City::City(Matrix& height,Matrix& junction,size_t carrinCapasity)
{
	this->height=height;
	this->junction=junction;
	this->carringCapasity=carrinCapasity;
}
void City::startSimulation(std::list<Simulation>& sim)
{
	size_t numberOfSimulation;
	std::cin>>numberOfSimulation;
	for(size_t i=0; i <numberOfSimulation;++i)
	{
		int liters, time;
		std::cin>>liters>>time;
		Simulation newSimulation(liters,time);
		sim.push_back(newSimulation);
	}
}
void City::simulation()
{
	std::list<Simulation> numberOfSimulation;
	startSimulation(numberOfSimulation);
	while(numberOfSimulation.size()>0)
	{

		Simulation simul = numberOfSimulation.front();
		numberOfSimulation.pop_front();
		junction.init(simul);
		//junction.print();
		while(simul.time>0)
		{
			drain(simul);

		}
		junction.print();
	}


}

void City::drain(Simulation& simul)
{

	int  row = junction.getM();
	int col = junction.getN();

	for(int i = 0; i < row; ++i)
	{
		for(int j=0; j< col; ++j)
		{
			if((j-1) < 0 && junction.getElem(i,j)>0 )
			{
				junction.setElem(i,j,(junction.getElem(i,j) -2*carringCapasity)>0?
						(junction.getElem(i,j) -2*carringCapasity):0);
			}
			if((j+1) == col && junction.getElem(i,j)>0)
			{
				junction.setElem(i,j,(junction.getElem(i,j) -2*carringCapasity)>0?
						(junction.getElem(i,j) -2*carringCapasity):0);
			}
			if((i-1) < 0  && junction.getElem(i,j)>0)
			{
				junction.setElem(i,j,(junction.getElem(i,j) -2*carringCapasity)>0?
						(junction.getElem(i,j) -2*carringCapasity):0);
			}
			if((i+1)==row && junction.getElem(i,j)>0)
			{
				junction.setElem(i,j,(junction.getElem(i,j) -2*carringCapasity)>0?
						(junction.getElem(i,j) -2*carringCapasity):0);
			}
			size_t counter =0;
			bool street[4] = {0,0,0,0};
			if(i+1<row && junction.getElem(i,j)>0)
			{
				if( height.getElem((i+1),j) < height.getElem(i,j) )
				{
					++counter;
					street[0]=true;
				}
			}

			if(i-1>=0 && junction.getElem(i,j)>0)
			{
				if( height.getElem((i-1),j) < height.getElem(i,j) )
				{
					++counter;
					street[2]=true;
				}
			}
			if(j+1<col && junction.getElem(i,j)>0)
			{
				if( height.getElem(i,j+1) < height.getElem(i,j) )
				{
					++counter;
					street[1]=true;
				}
			}
			if(j-1>=0 && junction.getElem(i,j)>0)
			{
				if( height.getElem(i,j-1) < height.getElem(i,j) )
				{
					++counter;
					street[3]=true;
				}
			}

			if(counter)
			{
				double liters= this->carringCapasity/counter;
				drainInside(liters,street,4,i,j);
				double newLiters;
				if((junction.getElem(i,j)-this->carringCapasity)<0)
				{
					newLiters= 0;
				}else{
					newLiters =junction.getElem(i,j)-this->carringCapasity;
				}

				junction.setElem(i,j,newLiters);
			}
		}
	}
	simul.time--;
}
void City::drainInside(double liters, bool* street, size_t size, size_t x, size_t y)
{
	for(size_t i =0 ; i < size; ++i)
	{
		if(street[i])
		{
			switch (i) {
				case 0:
					junction.setElem(x+1,y,(junction.getElem(x+1,y)+liters));
					break;
				case 1:
					junction.setElem(x,y+1,(junction.getElem(x,y+1)+liters));
					break;
				case 2:
					junction.setElem(x-1,y,(junction.getElem(x-1,y)+liters));
					break;
				case 3:
					junction.setElem(x,y-1,(junction.getElem(x,y-1)+liters));
					break;
				default:
					break;
			}
		}
	}
}

