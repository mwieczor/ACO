#pragma once
#include "Ant.hpp"
#include <boost/optional.hpp>

class BestPosition{
public:
    BestPosition(){}// to tests
    BestPosition(std::vector<std::reference_wrapper<Edge>> neighbour):
    neighbour(neighbour){}
    boost::optional<Edge> calc();

private:
    double probabilityNodeChosen(const Edge &E);
    boost::optional<Edge> chooseBestPosition(const std::vector<std::reference_wrapper<Edge>> &neighbours) const;
    void calculateProbability();
     int bestProbabilityPosition() const;
     void fillNodeProbability();

     std::vector<std::reference_wrapper<Edge>> neighbour;
     std::vector<double> probability;
     double mProbability=0;
     double mNodeProbability=0;
     std::vector<double> nodeProbability;
     boost::optional<Edge> bestPosition;
};
