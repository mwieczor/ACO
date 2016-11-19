#include "Scheduler.hpp"

void Scheduler::schedule()
{
    prepareDataForGraph();
//	mSchedule.emplace(x,y);
}

std::string Scheduler::getSchedule()
{
    auto temp = mBusStop[0];
    return (temp.isDemand)? temp.mName: "None";
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
    //auto lFirstPassenger = mPassengersList.top();
    mStartTime.hour +=1;
    findDemandStops();
    signPassengerToStop();
//    if(lPass.mTime >mStartTime){
//    while (lPass.mTime < mStartTime) {
//        mPassangersList.pop();
//        mPassangers.push_back(lPass);
//        lPass = mPassangersList.top();
//    }
//    }
//    else mStartTime.hour +=1;
      mAntColony = std::make_unique<EltistAntSystem>(lStartStop, *mGraph);

}

void Scheduler::findDemandStops()
{

    for(auto p: mPassengersList)
    {
        auto searchStop = p.mStartStop;
        auto it =std::find_if(mBusStop.begin(), mBusStop.end(), [&](auto&& s){
            return s.mName == searchStop;
        });
        if(it != mBusStop.end() )
            it->isDemand = true;
        //        for (auto k :mBusStop){
        //            if(k.mName.compare(searchStop))
        //                k.isDemand = true;
        //        }
    }
}

void Scheduler::signPassengerToStop()
{

}
