#pragma once

#include "Coordinate.hpp"
#include <memory>

struct Passenger;
struct Time;

class IBus {
public:
  IBus() {}
  virtual ~IBus() = default;
  virtual void ride(Coordinate) = 0;
  virtual Coordinate getPosition() const = 0;
  virtual void releaseSeat(std::pair<Time, std::string>) = 0;
  virtual int getNbOfPassengers() const = 0; // Is it nessesary?
  virtual void increasePassengersNumber(int) = 0;
  virtual bool areFreeSeatsInBus() = 0;
  virtual void takeASeat(Passenger) =0;
  virtual bool hasToBackToDepot() =0;
};
