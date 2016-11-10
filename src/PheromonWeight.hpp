#pragma once

#include  "Ant.hpp"

class WeightGraph;
class Node;

class PheromonWeight{
public:
    PheromonWeight(){}
    virtual ~PheromonWeight()=default;
protected:
    virtual void leavePheromon(WeightGraph &mGraph, Node lastNode, Node position, double weight);
//    virtual void leavePheromon(WeightGraph &mGraph, Node lastNode, Node position);
    virtual void evaporatePheromon(WeightGraph &mGraph);
};




