#pragma once

#include "Travel.hpp"
#include "PheromonWeight.hpp"

class AntColony: public Travel{


    // Travel interface
public:
    void generateRoute() override;
private:
    PheromonWeight weight;
};
