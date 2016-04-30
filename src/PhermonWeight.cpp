#include "PheromonWeight.hpp"



void PheromonWeight::leavePheromon(WeightGraph &mGraph, Edge mE){
    mGraph.changeEdgeWeight(mE, 5); ///TODO  initial pheromon weight
}

void PheromonWeight::evaporatePheromon(WeightGraph &mGraph)
{
    for(auto& edge:mGraph){
       edge.setWeight(edge.getWeight()-edge.getWeight()*(edge.getMlenght()/(double)100));

    }
}


