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
	mPassangersList.push(Passanger(pTime, timeWindow, pStartStop, pFinalStop));
}

std::string Scheduler::getPassanger()
{
	return mPassangersList.top().mFinalStop;
}
