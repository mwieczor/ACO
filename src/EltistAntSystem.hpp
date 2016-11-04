#pragma once
#include "Travel.hpp"
#include <algorithm>
#include "PheromonWeight.hpp"

class EltistAntSystem: public PheromonWeight
{
public:
    EltistAntSystem(){}
    EltistAntSystem(Node mStart, WeightGraph &mG):
    startCity(mStart), mGraph(mG){}
    void generateRoute();
    double getRouteLenght();
    void createAntColony();

    Node getFinalCity() const;

    void setFinalCity(const Node &value);

private:
    bool isFinalCity();

    WeightGraph mGraph;
    Node startCity;
    Node finalCity;
    double weight;
    void leaveAdditionalPheromon(Node lastNode, Node mN2);
    std::vector <std::pair<Ant, double>> mAntColony;
     size_t colonySize =10;
     double routeLenght;
};
