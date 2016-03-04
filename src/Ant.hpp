#pragma once

#include "Coordinate.hpp"

class Ant{
public:
    Ant(){}
    Ant(Coordinate antC):
        mCoordinate(antC){}


private:
    Coordinate mCoordinate;
    int phermonon; //wartosc stala?
};
