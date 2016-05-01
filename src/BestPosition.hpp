#pragma once
#include "Ant.hpp"
#include <boost/optional.hpp>
#include <list>
#include <utility>

class BestPosition{
public:
    BestPosition(){}// to tests
    BestPosition(std::vector<std::reference_wrapper<Edge>> neighbour):
        neighbour(neighbour){}
    Edge calc();

private:
    double probabilityNodeChosen(const Edge &E);
    Edge chooseBestPosition() ;
    void calculateProbability();
    int bestProbabilityPosition();
    void fillNodeProbability();
    bool isProbabilityEnoughtToMove(double probability) const;
    void generateRandom();
    double findHighestProbability();


    std::vector<std::reference_wrapper<Edge>> neighbour;
    //std::vector<double> probability;
    double mProbability=0;
    double mNodeProbability=0;
    std::list<std::pair<int,double>> nodeProbability;
    boost::optional<Edge> bestPosition;
    double random;

};
