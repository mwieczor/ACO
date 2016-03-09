#pragma once

#include "WeightGraph.hpp"

class Ant{
public:
    Ant(){}
    Ant(Coordinate antC):
        mCoordinate(antC){} // czy potrzebne?

    Ant(Node mN):
        mPosition(mN){}

    void choosePath();
    void leavePheromon();
    void changePosition(const Node &mN);



    Node position() const;
    void setPosition(const Node &position);

private:
    Coordinate mCoordinate;
    int phermonon; //wartosc stala?
    Node mPosition;
};
