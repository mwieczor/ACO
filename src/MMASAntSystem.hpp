#pragma once
#include "PheromonWeight.hpp"
#include "Travel.hpp"

class MMASAntSystem: public Travel, PheromonWeight{
    // Travel interface
public:
    void setStartGraphWeight() override;
    void generateRoute() override;

private:
    double maxWeight;
    double minWeight;
    // PheromonWeight interface
protected:
    void leavePheromon(WeightGraph &mGraph, Node lastNode, Node position) override;
    void evaporatePheromon(WeightGraph &mGraph) override;

};
