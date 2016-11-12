#pragma once

#include "Coordinate.hpp"

class IBus
{
public:
	IBus(){}
	virtual ~IBus() = default;
	virtual void ride() =0;
	virtual Coordinate getPosition() const =0;
};
