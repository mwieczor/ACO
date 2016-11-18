#pragma once

#include <map>
#include <string>
#include <vector>
#include <queue>
#include <memory>
#include "Bus.hpp"

    auto cmp = [](Passenger p1, Passenger p2){ return p1.mTime > p2.mTime ||(p1.mTime ==p2.mTime && p1.mTimeWindow > p2.mTimeWindow);};

class Scheduler{
public:
    Scheduler(const IBus& pBus, const auto& pBusStop):
    mPassangersList(cmp), mBus(pBus), mStartTime(6,0),mBusStop(pBusStop) {}
	void schedule(Time x, std::string y);
	std::string getSchedule();
	void addPassanger(Time, int, std::string, std::string);
	std::string getPassanger();
    std::string getBusStop();
    void prepareDataForGraph();
	
	
private:
    const IBus& mBus;
	std::map<Time, std::string> mSchedule;
    const std::vector<BusStop>& mBusStop;
    std::priority_queue<Passenger, std::vector<Passenger>, decltype (cmp)> mPassangersList;
    int mTimePeriod;
    Time mStartTime;
};
