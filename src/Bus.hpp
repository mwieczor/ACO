#pragma once

#include "IBus.hpp"


class Bus: public IBus 
{
public:
	Bus(Coordinate pPosition, int pCapacity):
	mPosition(pPosition), mCapacity(pCapacity), mPassangers() {}
	void ride(Coordinate) override;
	Coordinate getPosition() const override;
	void releaseSeat(int );
	int getNbOfPassangers() const;
	void increasePassangersNumber(int );
	bool areFreeSeatsInBus();
	
private:
	Coordinate mPosition;
	int mCapacity;
	int mPassangers;
};
