#pragma once

#include "IBus.hpp"


class Bus: public IBus 
{
public:
	Bus(Coordinate pPosition, int pCapacity):
	mPosition(pPosition), mCapacity(pCapacity), mPassangers() {}
	void ride(Coordinate) override;
	Coordinate getPosition() const override;
	void releaseSeat(int ) override;
	int getNbOfPassangers() const override; //Is it nessesary?
	void increasePassangersNumber(int ) override ;

	
private:
	bool areFreeSeatsInBus();
	Coordinate mPosition;
	int mCapacity;
	int mPassangers;
};
