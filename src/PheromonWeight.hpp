#pragma once

#include  "Ant.hpp"
class PheromonWeight{
public:
    PheromonWeight(){}
      void leavePheromon(WeightGraph &mGraph, Edge mE);
      void evaporatePheromon(WeightGraph &mGraph);

private:


};
