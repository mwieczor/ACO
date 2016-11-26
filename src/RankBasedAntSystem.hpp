#pragma once

#include "Travel.hpp"
#include "PheromonWeight.hpp"

class RankBasedAntSystem: public Travel, PheromonWeight{
    // Travel interface
public:
    void setStartGraphWeight() override;
    void generateRoute() override;

    // PheromonWeight interface


     // PheromonWeight interface
protected:
     void leavePheromon(IWeightGraph &mGraph, Node lastNode, Node position, double weight) override;
};
