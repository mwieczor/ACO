#pragma once

#include "Ant.hpp"
#include "WeightGraph.hpp"

class Node;

class Travel{
public:
    Travel()=default;
    Travel(Node mStart,Node finalCity, WeightGraph &mG):
     mGraph(mG),  startCity(mStart), finalCity(finalCity){}
    virtual void setStartGraphWeight();
    virtual void createAntColony();
    virtual void generateRoute()=0;
    void travelToString(); // display the best route
    void generateTravel();
   // double getRouteLenght();

    Node getFinalCity() const;

    bool isFinalCity();

    virtual ~Travel()= default;

    void setFinalCity(const Node &value);

    void setStartCity(const Node &value);

protected:
    void createGraph();
    std::vector <std::pair<Ant, double>> mAntColony;
     WeightGraph mGraph;

    Node startCity;
    Node finalCity;
    double routeLenght;
    double defaultWeight;
    size_t colonySize =10;
};
