#pragma once
#include "Travel.hpp"
#include <algorithm>
#include "PheromonWeight.hpp"

class EltistAntSystem: public Travel, PheromonWeight
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
    double weight;
    void leaveAdditionalPheromon(Node lastNode, Node mN2);
};
