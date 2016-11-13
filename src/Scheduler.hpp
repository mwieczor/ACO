#pragma once

#include <map>
#include <string>

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

class Scheduler{
public:
	Scheduler(){}
	void schedule(Time x, std::string y);
	std::string getSchedule();
	
private:
	std::map<Time, std::string> mSchedule;
};
