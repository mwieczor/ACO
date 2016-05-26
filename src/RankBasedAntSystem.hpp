#pragma once

#include "Travel.hpp"
#include "PheromonWeightRankBased.hpp"

class RankBasedAntSystem: public Travel{
    // Travel interface
public:
    void setStartGraphWeight() override;
    void generateRoute() override;

private:
    PheromonWeightRankBased weight;
};
