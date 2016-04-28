#pragma once

#include  "Ant.hpp"
class PheromonWeight{
public:
    PheromonWeight(){}
      virtual void leavePheromon(WeightGraph &mGraph, Edge mE);
      virtual void evaporatePheromon(WeightGraph &mGraph);

private:


};




