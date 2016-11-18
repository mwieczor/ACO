#pragma once

#include "IBus.hpp"
#include <vector>
#include <string>
#include <chrono>

struct Time
{
    Time(int x, int y):
        hour(x), minute(y){}
    int hour;
    int minute;
    bool operator==(const Time& c1) const
    {
        return hour==c1.hour && minute == c1.minute;
    }
    bool operator>(const Time& c1) const
    {
        return hour>c1.hour || (hour==c1.hour && minute > c1.minute);
    }
    bool operator<(const Time& c1) const
    {
        return hour<c1.hour || (hour==c1.hour && minute < c1.minute);
    }

};
struct Passenger{
    Passenger(Time pTime, int pTimeWindow, std::string pStartStop, std::string pFinalStop):
        mTime(pTime), mTimeWindow(pTimeWindow), mStartStop(pStartStop), mFinalStop(pFinalStop){}

    Time mTime;
    int mTimeWindow;
    std::string mStartStop;
    std::string mFinalStop;

};

struct BusStop
{
  BusStop(Coordinate pStop, std::string pName):
  mStop(pStop), mName(pName){}
  Coordinate mStop;
  std::string mName;
  bool isDemand =false;
  std::vector<Passenger> mPassangersList;

};

class Bus: public IBus 
{
public:
	Bus(Coordinate pPosition, int pCapacity):
	mPosition(pPosition), mCapacity(pCapacity), mPassangers() {}
	void ride(Coordinate) override;
	Coordinate getPosition() const override;
	void releaseSeat(int ) override;
	int getNbOfPassangers() const override; //Is it nessesary?
	void increasePassangersNumber(int ) override ;

	
private:
	bool areFreeSeatsInBus();
	Coordinate mPosition;
	int mCapacity;
	int mPassangers;
};
