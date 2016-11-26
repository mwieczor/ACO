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
    void leavePheromon(IWeightGraph &mGraph, Node lastNode, Node position, double w) override;
    void evaporatePheromon(IWeightGraph &mGraph) override;

};
