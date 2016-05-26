#pragma once
#include "Travel.hpp"
#include <algorithm>
#include "PheromonWeightEltist.hpp"

class EltistAntSystem: public Travel
{
public:
    EltistAntSystem(){}
    EltistAntSystem(Node mStart, WeightGraph &mG):
    startCity(mStart), mGraph(mG){}
    void generateRoute();

private:
    std::vector <std::pair<Ant, double>> mAntColony;
    WeightGraph mGraph;
    Node startCity;
    Node finalCity;
    PheromonWeightEltist weight;
};
