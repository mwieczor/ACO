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
    bool operator!=(const Node &other ) const {
        return other.mCoordinate!=this->mCoordinate;
    }

    Coordinate coordinate() const;

private:
    Coordinate mCoordinate;
};
