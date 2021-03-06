#include "Scheduler.hpp"
#include <fstream>

void Scheduler::setRouteParameters()
{
    mAntColony.setFinalCity(mFinalCity);
    mAntColony.setStartCity(mStartStop);
    mAntColony.setGraph(*mGraph);
}

void Scheduler::schedule(std::vector<std::string> pPassangerData) {
  preparePassangerData(pPassangerData);
  prepareDataForGraph();
  if(mSchedule.size()==0){
      setRouteParameters();
      auto lRawSchedule = mAntColony.getCalculateRoute();
	  calculateSchedule(lRawSchedule);
  }
  saveScheduleToFile();
}

std::map<Time, std::string> Scheduler::getSchedule() 
 {
  return mSchedule;
}

void Scheduler::addPassanger(Time pTime, std::string pStartStop,
                             std::string pFinalStop) {
  mPassengersList.push_back(
      Passenger(pTime, pStartStop, pFinalStop));
}

std::string Scheduler::getPassanger() { return mPassengersList[0].mFinalStop; }

std::string Scheduler::getBusStop() { return mBusStop[0].mName; }

void Scheduler::prepareDataForGraph() {
  findDemandStops();
  if (isPassangerInTimeWindow){
      mStartStop = mBus->getPosition();
	  mFinalCity = findFinalCity();
	  mGraph->createGraph(mBusStop);
  }
  
  else{
	  mSchedule.clear();
	  mSchedule.emplace(Time(0,0) , "No passengers in this time");
  }
}

void Scheduler::findDemandStops() 
{
  isPassangerInTimeWindow = false;
  for (auto p : mPassengersList) {
    if (p.mTime < mStartTime + Time(0, 30)) {
      isPassangerInTimeWindow = true;
      auto searchStop = p.mStartStop;
      auto it = std::find_if(mBusStop.begin(), mBusStop.end(),
                             [&](auto &&s) { return s.mName == searchStop; });
      if (it != mBusStop.end()) {
        signPassengerToStop(it, p);
      }
    }
  }
}

void Scheduler::signPassengerToStop(std::vector<BusStop>::iterator &it,
                                    Passenger &p) {
  if (p.mTime <= mStartTime &&
      ((p.mTime + Time(0, p.mTimeWindow)) >= mStartTime)) {
    it->addPassengerToStop(p);
    it->isDemand = true;
  }
}

void Scheduler::calculateSchedule(
    std::vector<std::pair<Coordinate, int>> &pRawSchedule) {
  for (auto lRawStop : pRawSchedule) {
    auto it =
        std::find_if(mBusStop.begin(), mBusStop.end(), [=](auto lBusStop) {
          return lBusStop.mStop == lRawStop.first;
        });
    mSchedule.insert({mStartTime + Time(0, lRawStop.second), it->mName});
  }
  incraseNbOfPassangerInBus();
}

void Scheduler::setPassangersToSchedule(int nb, std::pair<Time, std::string> b)
{
  while (nb > 0) {
    auto passanger = std::find_if(mPassengersList.begin(), mPassengersList.end(),
                 [&](auto p) { return b.second == p.mStartStop; });
	if(passanger!=mPassengersList.end()){
    mBus->takeASeat(*passanger);
	mPassengersList.erase(passanger);
	nb--;
	}
	else break;
  }
}

void Scheduler::incraseNbOfPassangerInBus() // wrong name, do two diff things{
{
  for (auto b : mSchedule) {

    mBus->releaseSeat(b);
    auto freeSeats = mBus->getFreeSeatsInBus();
    if (freeSeats) {
      auto nb = std::count_if(mPassengersList.begin(), mPassengersList.end(),
                              [=](auto p) { return b.second == p.mStartStop; });
	  if(freeSeats>nb){
      mBus->increasePassengersNumber(nb);
      setPassangersToSchedule(nb, b);
	  }
	  else{
          mBus->increasePassengersNumber(freeSeats);
		  setPassangersToSchedule(freeSeats, b); 
	  }
    }
  }
}

void Scheduler::parseData(std::vector<std::__cxx11::string> pData)
{
    for(int i =pData.size()-1; i>=0 ; i=i-3)
    {
    mBusStop.push_back(BusStop({Coordinate(std::stoi(pData[i-2], nullptr), std::stoi(pData[i-1], nullptr)), pData[i]}));
    }
}

Coordinate Scheduler::findFinalCity()
{
    if(mBus->hasToBackToDepot()){
		return mDepotCoordinate;
	}
	else {
		Time bestTime= mPassengersList.begin()->mTime;
		Passenger p1 = {Time(0,0), {}, {}};
                for (auto p : mPassengersList) {
                  if (bestTime > p.mTime) {
                    bestTime = p.mTime;
                    p1 = p;
                  }
                }
				auto busStop= std::find_if(mBusStop.begin(), mBusStop.end(), [=](auto b){
					return p1.mStartStop== b.mName;
				});
						return busStop->mStop;
        }
}
bool isRightTime(Time passTime){
	
}

void Scheduler::setStartTime(const Time &startTime) { mStartTime = startTime; }

void Scheduler::saveScheduleToFile()
{
    std::ofstream outfile ("/home/mwieczor/gotowyRozklad.csv", std::ofstream::out);
    for (auto t : mSchedule)
    {
        outfile<< std::to_string(t.first.hour) +","+ std::to_string(t.first.minute) +","+t.second +"\n";
    }
}

void Scheduler::preparePassangerData(std::vector<std::__cxx11::string> & pData)
{
    for(int i =pData.size()-1; i>=0 ; i=i-4)
    {
    addPassanger(Time(std::stoi(pData[i-3], nullptr), std::stoi(pData[i-2], nullptr)), pData[i-1], pData[i]);
    }
}
