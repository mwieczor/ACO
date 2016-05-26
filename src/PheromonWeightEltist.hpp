#pragma once

#include "PheromonWeight.hpp"

class PheromonWeightEltist: public PheromonWeight{
public:
    PheromonWeightEltist(){}
    void leaveAdditionalPheromon(WeightGraph &g, Node mN1, Node mN2);
    void leavePheromon(WeightGraph &mGraph, Node lastNode, Node position);
private:
    double weight;


};
