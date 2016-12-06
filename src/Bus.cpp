#include "Bus.hpp"
#include "Coordinate.hpp"
#include "algorithm"

void Bus::ride(Coordinate pPosition) { mPosition = pPosition; }

Coordinate Bus::getPosition() const { return mPosition; }

void Bus::releaseSeat(std::pair<Time, std::string> pBusStop) { 
	auto nb = std::count_if(mPassengersList.begin(), mPassengersList.end(),
                            [=](auto p) { return pBusStop.second == p.mFinalStop; });
	mPassangers = mPassangers - nb; 
	while (nb > 0) {
	  auto passanger = std::find_if(mPassengersList.begin(), mPassengersList.end(),
				   [&](auto p) { return pBusStop.second == p.mStartStop; });
	  if(passanger!=mPassengersList.end()){
	  mPassengersList.erase(passanger);
	  nb--;
	  }
	  else break;
	}
}

int Bus::getNbOfPassengers() const { return mPassangers; }

void Bus::increasePassengersNumber(int pPassangers) {
  if (areFreeSeatsInBus() && mPassangers + pPassangers <= mCapacity)
    mPassangers += pPassangers;
  else
    mPassangers = mCapacity; // blad, brak info o tym, ze nie zabrano pasazerow
}

bool Bus::areFreeSeatsInBus() { return mPassangers < mCapacity; }


void Bus::takeASeat(Passenger p)
{
	mPassengersList.push_back(p); 
	
}
