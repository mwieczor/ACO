#pragma once

#include "IBus.hpp"


class Bus: public IBus 
{
public:
	Bus(Coordinate pPosition, int pCapacity):
	mPosition(pPosition), mCapacity(pCapacity){}
	void ride() override;
	Coordinate getPosition() const override;
	void releaseSeat(int );
	int getCapacity() const;
	
private:
	Coordinate mPosition;
	int mCapacity;
};
