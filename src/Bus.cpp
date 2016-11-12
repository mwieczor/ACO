#include "Bus.hpp"
#include "Coordinate.hpp"

void Bus::ride()
{
	
}

Coordinate Bus::getPosition() const
{
	return mPosition;
}

void Bus::releaseSeat(int pPassangers)
{
	mPassangers -= pPassangers;
}

int Bus::getNbOfPassangers() const
{
	return mPassangers;
}

void Bus::increasePassangersNumber(int pPassangers)
{
	if(areFreeSeatsInBus())
		mPassangers +=pPassangers;
}

bool Bus::areFreeSeatsInBus()
{
	return mPassangers<mCapacity;
}
