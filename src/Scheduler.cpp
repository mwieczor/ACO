#include "Scheduler.hpp"

void Scheduler::schedule(Time x, std::string y)
{
	mSchedule.emplace(x,y);
}

std::string Scheduler::getSchedule()
{
	return mSchedule.begin()->second;
}
