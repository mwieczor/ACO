#pragma once

#include <map>
#include <string>
#include <vector>
#include <queue>

struct Time
{
	Time(int x, int y):
		hour(x), minute(y){}
	int hour;
	int minute;
	bool operator==(const Time& c1) const
	{
		return hour==c1.hour && minute == c1.minute;
	}
	bool operator>(const Time& c1) const
	{
		return hour>c1.hour || (hour==c1.hour && minute > c1.minute);
	}
	bool operator<(const Time& c1) const
	{
		return hour<c1.hour || (hour==c1.hour && minute < c1.minute);
	}
	
};

struct Passanger{
	Passanger(Time pTime, int pTimeWindow, std::string pStartStop, std::string pFinalStop):
		mTime(pTime), mTimeWindow(pTimeWindow), mStartStop(pStartStop), mFinalStop(pFinalStop){}
	
	Time mTime;
	int mTimeWindow;
	std::string mStartStop;
	std::string mFinalStop;
	
};
	auto cmp = [](Passanger p1, Passanger p2){ return p1.mTime > p2.mTime ||(p1.mTime ==p2.mTime && p1.mTimeWindow > p2.mTimeWindow);};

class Scheduler{
public:
	Scheduler():
	mPassangersList(cmp){}
	void schedule(Time x, std::string y);
	std::string getSchedule();
	void addPassanger(Time, int, std::string, std::string);
	std::string getPassanger();
	
	
private:
	std::map<Time, std::string> mSchedule;
	std::vector<Passanger> mPassangers;
	std::priority_queue<Passanger, std::vector<Passanger>, decltype (cmp)> mPassangersList;
};
