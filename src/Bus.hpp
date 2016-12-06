#pragma once

#include "IBus.hpp"
#include <ctime>
#include <string>
#include <vector>

struct Time {
  Time(int x, int y) : hour(x), minute(y) {}
  int hour;
  int minute;
  bool operator==(const Time &c1) const {
    return hour == c1.hour && minute == c1.minute;
  }
  bool operator>(const Time &c1) const {
    return hour > c1.hour || (hour == c1.hour && minute > c1.minute);
  }
  bool operator>=(const Time &c1) const {
    return hour >= c1.hour || (hour == c1.hour && minute >= c1.minute);
  }
  bool operator<=(const Time &c1) const {
    return hour <= c1.hour || (hour == c1.hour && minute <= c1.minute);
  }
  bool operator<(const Time &c1) const {
    return hour < c1.hour || (hour == c1.hour && minute < c1.minute);
  }
  Time operator+(const Time &c1) const {
    return Time(hour + c1.hour, minute + c1.minute);
  }
};
struct Passenger {
  Passenger(Time pTime, std::string pStartStop,
            std::string pFinalStop)
      : mTime(pTime), mTimeWindow(15), mStartStop(pStartStop), //przeniesc stala do schedulera
        mFinalStop(pFinalStop) {}

  Time mTime;
  int mTimeWindow;
  std::string mStartStop;
  std::string mFinalStop;
};

struct BusStop {
  BusStop(Coordinate pStop, std::string pName) : mStop(pStop), mName(pName) {}
  Coordinate mStop;
  std::string mName;
  bool isDemand = false;
  std::vector<Passenger> mPassengersList;
  void addPassengerToStop(Passenger p) { mPassengersList.push_back(p); }
  bool operator==(const BusStop &c1) const { return mStop == c1.mStop; }
};

class Bus : public IBus {
public:
  Bus(Coordinate pPosition)
      : mPosition(pPosition), mCapacity(50), mPassangers() {}
  void ride(Coordinate) override;
  Coordinate getPosition() const override;
  void releaseSeat(std::pair<Time, std::string>) override;
  int getNbOfPassengers() const override; // Is it nessesary?
  void increasePassengersNumber(int) override;
  bool areFreeSeatsInBus() override;
  void takeASeat(Passenger) override;
  

private:
  Coordinate mPosition;
  int mCapacity;
  int mPassangers;
  std::vector<Passenger> mPassengersList;
  
};
