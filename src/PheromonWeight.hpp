#pragma once

#include  "Ant.hpp"
class PheromonWeight{
public:
    PheromonWeight(){}
      virtual void leavePheromon(WeightGraph &mGraph, Node lastNode, Node position);
      virtual void evaporatePheromon(WeightGraph &mGraph);

private:


};




