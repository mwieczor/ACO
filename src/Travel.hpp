#pragma once

#include "Ant.hpp"
#include "WeightGraph.hpp"

class Node;

class Travel{
public:
    Travel(){}
    Travel(Node mStart,Node finalCity):
       startCity(mStart), finalCity(finalCity){
        std::vector<double> l_vector {1.2, 1.3, 1.4};
        mGraph= std::make_shared<WeightGraph>(l_vector);
    }
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
    std::vector <std::pair<Ant, double>> mAntColony;
     std::shared_ptr<WeightGraph> mGraph;

    Node startCity;
    Node finalCity;
    double routeLenght;
    double defaultWeight;
    size_t colonySize =10;
};
