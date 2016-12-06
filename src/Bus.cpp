#include "Bus.hpp"
#include "Coordinate.hpp"
#include "algorithm"

void Bus::ride(Coordinate pPosition, Time pTime) { mPosition = pPosition; mWorkingTime = mWorkingTime +pTime;}

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
  if (mPassangers + pPassangers <= mCapacity)
    mPassangers += pPassangers;
  else
    mPassangers = mCapacity;
}

int Bus::getFreeSeatsInBus() { return mCapacity-mPassangers; }


void Bus::takeASeat(Passenger p)
{
	mPassengersList.push_back(p); 	
}

bool Bus::hasToBackToDepot()
{
	if(mWorkingTime == Time(8,0)){
		doWorkingTimeReset();
		return true;
	}
	else return false;
}

void Bus::doWorkingTimeReset()
{
	mWorkingTime = Time(0,0);
}
