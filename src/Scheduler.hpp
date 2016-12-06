#pragma once

#include "Bus.hpp"
#include "EltistAntSystem.hpp"
#include "WeightGraph.hpp"
#include <map>
#include <memory>
#include <queue>
#include <string>
#include <vector>

// auto cmp = [](Passenger p1, Passenger p2){ return p1.mTime > p2.mTime
// ||(p1.mTime ==p2.mTime && p1.mTimeWindow > p2.mTimeWindow);};

class Scheduler {
public:
  Scheduler(IBus &pBus, auto &pBusStop, std::shared_ptr<IWeightGraph> pGraph,
            std::shared_ptr<IEltistAntSystem> pEltist)
      : mBus(pBus), mStartTime(0, 0), mBusStop(pBusStop), mGraph(pGraph),
        mAntColony(std::move(pEltist)) {}
  void schedule();
  std::map<Time, std::string> getSchedule();
  void addPassanger(Time, std::string, std::string);
  std::string getPassanger();
  std::string getBusStop();

  void setStartTime(const Time &startTime);

private:
  void prepareDataForGraph();
  void findDemandStops();
  void signPassengerToStop(std::vector<BusStop>::iterator &it, Passenger &);
  void calculateSchedule(std::vector<std::pair<Coordinate, int>> &);
  void setPassangersToSchedule(int, std::pair<Time, std::string>);
  void incraseNbOfPassangerInBus();
  Coordinate findFinalCity();

  std::shared_ptr<IEltistAntSystem> mAntColony;
  std::shared_ptr<IWeightGraph> mGraph;
  IBus &mBus;
  std::map<Time, std::string> mSchedule;
  std::vector<BusStop> &mBusStop;
  std::vector<Passenger> mPassengersList;
  int mTimePeriod;
  Time mStartTime;
  bool isPassangerInTimeWindow;
  Coordinate mDepotCoordinate;
};
