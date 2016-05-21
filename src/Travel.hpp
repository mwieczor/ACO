#pragma once

#include "Ant.hpp"
#include "WeightGraph.hpp"
#include "PheromonWeightEltist.hpp"

class Travel{
public:
    //bossTravel(){}
    Travel(Node mStart, WeightGraph &mG):
    startCity(mStart), mGraph(mG){}
    Travel(const WeightGraph &mG):
        mGraph(mG){}
    virtual void travelToString(); // display the best route
    void generateTravel();

    Node getFinalCity() const;
    void setFinalCity(const Node &value);

    Node getStartCity() const;
    void setStartCity(const Node &value);

    virtual double getRouteLenght();
    virtual bool isFinalCity();

private:
    void createGraph();


    std::vector <Ant> mAntColony;
    WeightGraph mGraph;
    Node startCity;
    Node finalCity;
    PheromonWeightEltist weight;
    double routeLenght;
};
