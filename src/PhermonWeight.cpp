#include "PheromonWeight.hpp"
#include "Node.hpp"

void PheromonWeight::leavePheromon(IWeightGraph &mGraph, Node lastNode, Node position, double weight){
    mGraph.changeEdgeWeight(lastNode, position, weight); ///TODO  initial pheromon weight
}

void PheromonWeight::evaporatePheromon(IWeightGraph &mGraph)
{
    for(auto& edge:mGraph){
       edge.setWeight(edge.getWeight()-edge.getWeight()*(edge.getLenght()/static_cast<double>(100)));

    }
}


