#pragma once

#include "PheromonWeight.hpp"

class PheromonWeightMMAS: public PheromonWeight{
public:
     void leavePheromon(WeightGraph &mGraph, Node lastNode, Node position) override;
     void evaporatePheromon(WeightGraph &mGraph) override;
private:
     double minWeight=0.1; ///TODO search value
};
