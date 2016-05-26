#pragma once

#include "PheromonWeight.hpp"

class PheromonWeightRankBased: public PheromonWeight{
public:
    // PheromonWeight interface
    void leavePheromon(WeightGraph &mGraph, Node lastNode, Node position ) override;
private:
    double maxWeight;


};
