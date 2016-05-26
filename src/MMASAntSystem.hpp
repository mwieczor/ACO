#pragma once
#include "PheromonWeightMMAS.h"
#include "Travel.hpp"

class MMASAntSystem: public Travel{
    // Travel interface
public:
    void setStartGraphWeight() override;
    void generateRoute() override;

private:
    double maxWeight;
    PheromonWeightMMAS weight;
};
