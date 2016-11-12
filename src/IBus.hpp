#pragma once

#include "Coordinate.hpp"

class IBus
{
public:
	IBus(){}
	virtual ~IBus() = default;
	virtual void ride(Coordinate) =0;
	virtual Coordinate getPosition() const =0;
	virtual void releaseSeat(int) =0;
	virtual int getNbOfPassangers() const =0; //Is it nessesary?
	virtual void increasePassangersNumber(int) =0;
};
