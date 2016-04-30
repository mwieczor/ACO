#pragma once

#include "PheromonWeight.hpp"

class PheromonWeightEltist: public PheromonWeight{
public:
    PheromonWeightEltist(){}
    void leaveAdditionalPheromon(WeightGraph &g, Edge &e);

};
