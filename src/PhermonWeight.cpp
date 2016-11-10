#include "PheromonWeight.hpp"
#include "Node.hpp"

void PheromonWeight::leavePheromon(WeightGraph &mGraph, Node lastNode, Node position, double weight){
    mGraph.changeEdgeWeight(lastNode, position, weight); ///TODO  initial pheromon weight
}

void PheromonWeight::evaporatePheromon(WeightGraph &mGraph)
{
    for(auto& edge:mGraph){
       edge.setWeight(edge.getWeight()-edge.getWeight()*(edge.getMlenght()/static_cast<double>(100)));

    }
}


