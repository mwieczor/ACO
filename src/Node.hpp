#pragma once

#include "Coordinate.hpp"

class Node{
public:
    Node(){}
    Node(Coordinate mN):
        mCoordinate(mN){}
    bool operator==(const Node &other ) const {
        return other.mCoordinate==this->mCoordinate;
    }

private:
    Coordinate mCoordinate;
};
