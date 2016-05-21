#pragma once

#include "PheromonWeight.hpp"

class PheromonWeightRankBased: public PheromonWeight{
public:
    void leavePheromon(WeightGraph &mGraph, Edge mE);
};
