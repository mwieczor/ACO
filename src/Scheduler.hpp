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
    Scheduler(const IBus& pBus):
    mPassangersList(cmp), mBus(pBus), mStartTime(6,0){}
	void schedule(Time x, std::string y);
	std::string getSchedule();
	void addPassanger(Time, int, std::string, std::string);
	std::string getPassanger();
    std::string getPassangers();
    void prepareDataForGraph();
	
	
private:
    const IBus& mBus;
	std::map<Time, std::string> mSchedule;
    std::vector<Passenger> mPassangers;
    std::priority_queue<Passenger, std::vector<Passenger>, decltype (cmp)> mPassangersList;
    int mTimePeriod;
    Time mStartTime;
};
