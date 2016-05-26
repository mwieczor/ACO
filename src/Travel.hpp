#pragma once

#include "Ant.hpp"
#include "WeightGraph.hpp"

class Travel{
public:
    Travel()=default;
    Travel(Node mStart,Node finalCity, WeightGraph &mG):
     mGraph(mG),  startCity(mStart), finalCity(finalCity){}
    virtual void setStartGraphWeight();
    virtual void createAntColony();
    virtual void generateRoute()=0;
    void travelToString(); // display the best route
    Node getFinalCity() const;
    void setFinalCity(const Node &value);

    Node getStartCity() const;
    //void setStartCity(const Node &value);

    virtual double getRouteLenght();
    bool isFinalCity();

    virtual ~Travel()= default;

protected:
    void createGraph();
    std::vector <std::pair<Ant, double>> mAntColony;
    WeightGraph mGraph;
    Node startCity;
    Node finalCity;
    double routeLenght;
    double defaultWeight;
    size_t colonySize;
};
