#pragma once

#include "Travel.hpp"
#include "PheromonWeight.hpp"

class RankBasedAntSystem: public Travel, PheromonWeight{
    // Travel interface
public:
    void setStartGraphWeight() override;
    void generateRoute() override;

    // PheromonWeight interface


private:
     void leavePheromon(WeightGraph &mGraph, Node lastNode, Node position) override;

};
