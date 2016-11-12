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
	mCapacity -= pPassangers;
}

int Bus::getCapacity() const
{
	return mCapacity;
}

void Bus::increasePassangersNumber(int pPassangers)
{
	mCapacity +=pPassangers;
}
