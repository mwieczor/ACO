#pragma once

#include <map>
#include <string>
#include <vector>
#include <queue>
#include <memory>
#include "Bus.hpp"
#include "EltistAntSystem.hpp"
#include "WeightGraph.hpp"

   // auto cmp = [](Passenger p1, Passenger p2){ return p1.mTime > p2.mTime ||(p1.mTime ==p2.mTime && p1.mTimeWindow > p2.mTimeWindow);};

class Scheduler{
public:
    Scheduler(const IBus& pBus, auto pBusStop):
    mBus(pBus), mStartTime(5,0),mBusStop(pBusStop) {
        mGraph = std::make_shared<WeightGraph>();
    }
    void schedule();
	std::string getSchedule();
	void addPassanger(Time, int, std::string, std::string);
	std::string getPassanger();
    std::string getBusStop();
	
	
    void setStartTime(const Time &startTime);

private:
    void prepareDataForGraph();
    void findDemandStops();
    void signPassengerToStop(std::vector<BusStop>::iterator it, Passenger&);
    std::unique_ptr<EltistAntSystem> mAntColony;
    std::shared_ptr<WeightGraph> mGraph;
    const IBus& mBus;
	std::map<Time, std::string> mSchedule;
    std::vector<BusStop> mBusStop;
    std::vector<Passenger>  mPassengersList;
    int mTimePeriod;
    Time mStartTime;
};
