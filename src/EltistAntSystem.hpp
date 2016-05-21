#pragma once
#include "Travel.hpp"
#include <algorithm>
class EltistAntSystem: public Travel
{
public:
    EltistAntSystem(){}
    EltistAntSystem(Node mStart, WeightGraph &mG):
    startCity(mStart), mGraph(mG){
        while(mAntColony.size()<10)
            mAntColony.push_back(std::make_pair(Ant(startCity),0));
    }
    void generateTravel();

private:
    std::vector <std::pair<Ant, double>> mAntColony;
    WeightGraph mGraph;
    Node startCity;
    Node finalCity;
    PheromonWeightEltist weight;
};
