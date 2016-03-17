#pragma once

#include "Ant.hpp"
#include "WeightGraph.hpp"

class Travel{
public:
    Travel(){}
    Travel(Node mStart):
    startCity(mStart){
        while(mAntColony.size()<10){
            mAntColony.push_back(Ant(startCity));
        }
    }
    Travel(const WeightGraph &mG):
        mGraph(mG){}
    void travelToString(); // generate the best route
    void generateTravel();

    Node getFinalCity() const;
    void setFinalCity(const Node &value);

    Node getStartCity() const;
    void setStartCity(const Node &value);

    void getMap(); //take a map from OSM

    int getRouteLenght() const;

private:
    void createGraph();
    bool isFinalCity();




    std::vector <Ant> mAntColony;
    WeightGraph mGraph;
    Node startCity;
    Node finalCity;
    int routeLenght;
};
