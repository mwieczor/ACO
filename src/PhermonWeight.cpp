#include "PheromonWeight.hpp"



void PheromonWeight::leavePheromon(WeightGraph &mGraph, Edge mE){
    mGraph.changeEdgeWeight(mGraph.edge(mE), 5); ///TODO  initial pheromon weight
}

void PheromonWeight::vanishPheromon(WeightGraph &mGraph)
{
    for(auto edge:mGraph.edgeCollection()){
        mGraph.edge(edge).setWeight(edge.getWeight().weight()-edge.getWeight().weight()*(edge.getMlenght()/(double)100));

    }
}
