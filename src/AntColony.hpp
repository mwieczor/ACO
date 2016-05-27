#pragma once

#include "Travel.hpp"
#include "PheromonWeight.hpp"

class AntColony: public Travel, PheromonWeight{
public:
    AntColony(Node mStart,Node finalCity, WeightGraph &mG):
        mGraph(mG),  startCity(mStart), finalCity(finalCity){}

    // Travel interface
    void generateRoute() override;

private:
    void createGraph();
    std::vector <std::pair<Ant, double>> mAntColony;
    WeightGraph mGraph;
    Node startCity;
    Node finalCity;
    double routeLenght;
    double weight;
    size_t colonySize;
};
