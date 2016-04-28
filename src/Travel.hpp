#pragma once

#include "Ant.hpp"
#include "WeightGraph.hpp"
#include "PheromonWeight.hpp"

class Travel{
public:
    Travel(){}
    Travel(Node mStart, WeightGraph &mG):
    startCity(mStart), mGraph(mG){ //only for tests
        while(mAntColony.size()<10){
            mAntColony.push_back(Ant(startCity));
        }
    }
    Travel(const WeightGraph &mG):
        mGraph(mG){}
    void travelToString(); // display the best route
    void generateTravel();

    Node getFinalCity() const;
    void setFinalCity(const Node &value);

    Node getStartCity() const;
    void setStartCity(const Node &value);

    double getRouteLenght();

private:
    void createGraph();
    bool isFinalCity();

    std::vector <Ant> mAntColony;
    WeightGraph mGraph;
    Node startCity;
    Node finalCity;
    PheromonWeight weight;
    double routeLenght;
};
