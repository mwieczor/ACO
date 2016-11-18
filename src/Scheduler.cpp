#include "Scheduler.hpp"

void Scheduler::schedule(Time x, std::string y)
{
	mSchedule.emplace(x,y);
}

std::string Scheduler::getSchedule()
{
	return mSchedule.begin()->second;
}

void Scheduler::addPassanger(Time pTime, int timeWindow, std::string pStartStop, std::string pFinalStop)
{
    mPassangersList.push(Passenger(pTime, timeWindow, pStartStop, pFinalStop));
}

std::string Scheduler::getPassanger()
{
	return mPassangersList.top().mFinalStop;
}

std::string Scheduler::getPassangers()
{
    return mPassangers[0].mFinalStop;
}
void Scheduler::prepareDataForGraph()
{
    auto lStartStop =mBus.getPosition();
    //mPassangers.push_back(Passanger(mStartTime, 0, lStartStop, lStartStop));
    auto lPass = mPassangersList.top();
    mStartTime.hour +=1;
//    if(lPass.mTime >mStartTime){
//    while (lPass.mTime < mStartTime) {
//        mPassangersList.pop();
//        mPassangers.push_back(lPass);
//        lPass = mPassangersList.top();
//    }
//    }
//    else mStartTime.hour +=1;

}
