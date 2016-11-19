#include "Bus.hpp"
#include "Coordinate.hpp"

void Bus::ride(Coordinate pPosition)
{
	mPosition = pPosition;
}

Coordinate Bus::getPosition() const
{
	return mPosition;
}

void Bus::releaseSeat(int pPassangers)
{
	mPassangers -= pPassangers;
}

int Bus::getNbOfPassengers() const
{
	return mPassangers;
}

void Bus::increasePassengersNumber(int pPassangers)
{
  if (areFreeSeatsInBus() && mPassangers + pPassangers <= mCapacity)
    mPassangers += pPassangers;
  else
    mPassangers = mCapacity;
}

bool Bus::areFreeSeatsInBus()
{
	return mPassangers < mCapacity;
}
