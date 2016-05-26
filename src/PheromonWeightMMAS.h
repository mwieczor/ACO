#pragma once

#include "PheromonWeight.h"

class PheromonWeightMMAS: public PheromonWeight{
public:
     void leavePheromon(WeightGraph &mGraph, Node lastNode, Node position);
private:
    double maxWeight;

};
