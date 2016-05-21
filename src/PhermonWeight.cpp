#include "PheromonWeight.hpp"



void PheromonWeight::leavePheromon(WeightGraph &mGraph, Node lastNode, Node position){
    mGraph.changeEdgeWeight(lastNode, position); ///TODO  initial pheromon weight
}

void PheromonWeight::evaporatePheromon(WeightGraph &mGraph)
{
    for(auto& edge:mGraph){
       edge.setWeight(edge.getWeight()-edge.getWeight()*(edge.getMlenght()/(double)100));

    }
}


