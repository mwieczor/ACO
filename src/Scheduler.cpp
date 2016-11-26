#include "Scheduler.hpp"

void Scheduler::schedule()
{
    prepareDataForGraph();
	//mAntColony = std::make_unique<EltistAntSystem>(lStartStop, lFinalCity, *mGraph);
	auto lRawSchedule = mAntColony->getCalculateRoute();
	calculateSchedule();
}

std::string Scheduler::getSchedule()
{
	auto temp = std::find_if(mBusStop.begin(), mBusStop.end(), [](auto s) {return s.isDemand;});
    return (temp!= mBusStop.end())? temp->mName: "No passengers in this time";
}

void Scheduler::addPassanger(Time pTime, int timeWindow, std::string pStartStop, std::string pFinalStop)
{
    mPassengersList.push_back(Passenger(pTime, timeWindow, pStartStop, pFinalStop));
}

std::string Scheduler::getPassanger()
{
    return mPassengersList[0].mFinalStop;
}

std::string Scheduler::getBusStop()
{
    return mBusStop[0].mName;
}
void Scheduler::prepareDataForGraph()
{
    auto lStartStop =mBus.getPosition();
	auto lFinalCity = Coordinate(5,6);
    findDemandStops();
    mGraph->createGraph(mBusStop);
}

void Scheduler::findDemandStops()
{
    for(auto p: mPassengersList)
    {
        auto searchStop = p.mStartStop; 
        auto it =std::find_if(mBusStop.begin(), mBusStop.end(), [&](auto&& s){
            return s.mName == searchStop;
        });
        if(it != mBusStop.end() ){
            signPassengerToStop(it, p);
        }
    }
}

void Scheduler::signPassengerToStop(std::vector<BusStop>::iterator& it, Passenger& p )
{
    if(p.mTime <= mStartTime &&( (p.mTime+ Time(0,p.mTimeWindow) )>= mStartTime) )
    {
        it->addPassengerToStop(p);
        it->isDemand = true;
	}
}

void Scheduler::calculateSchedule()
{
	
}

void Scheduler::setStartTime(const Time &startTime)
{
    mStartTime = startTime;
}
