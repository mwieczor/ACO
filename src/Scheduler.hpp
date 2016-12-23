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

class   Scheduler {
public:
  Scheduler(IEltistAntSystem& pAntColony, std::vector<std::string> pBusStop, std::shared_ptr<IWeightGraph> pGraph)
      :  mAntColony(pAntColony), mStartTime(0, 0), mGraph(pGraph)
  {
      parseData(pBusStop);
      mBus = std::make_shared<Bus>(Coordinate(0,0));
  }
  void schedule(std::vector<std::string> );
  std::map<Time, std::string> getSchedule();
  void addPassanger(Time, std::string, std::string);
  std::string getPassanger();
  std::string getBusStop();

  void setStartTime(const Time &startTime);

private:
  void saveScheduleToFile();
  void preparePassangerData(std::vector<std::string>&);
  void prepareDataForGraph();
  void findDemandStops();
  void signPassengerToStop(std::vector<BusStop>::iterator &it, Passenger &);
  void calculateSchedule(std::vector<std::pair<Coordinate, int>> &);
  void setPassangersToSchedule(int, std::pair<Time, std::string>);
  void incraseNbOfPassangerInBus();
  void parseData(std::vector<std::string>);
  Coordinate findFinalCity();

  IEltistAntSystem& mAntColony;
  std::shared_ptr<IWeightGraph> mGraph;
  std::shared_ptr<IBus> mBus;
  std::map<Time, std::string> mSchedule;
  std::vector<BusStop> mBusStop;
  std::vector<Passenger> mPassengersList;
  int mTimePeriod;
  Time mStartTime;
  bool isPassangerInTimeWindow;
  Coordinate mDepotCoordinate;
  Coordinate mStartStop;
  Coordinate mFinalCity; 
  void setRouteParameters();
};
