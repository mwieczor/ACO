#include "PheromonWeightMMAS.h"


void PheromonWeightMMAS::leavePheromon(WeightGraph &mGraph, Node lastNode, Node position){ //only best iteratrion leave pheromon
    static double maxWeight=0.1;/// TODO search initial level of weight
    mGraph.changeEdgeWeight(lastNode, position, maxWeight);
}

void PheromonWeightMMAS::evaporatePheromon(WeightGraph &mGraph)
{
    for(auto& edge:mGraph){
        if(edge.getWeight()>minWeight)
            edge.setWeight(edge.getWeight()-edge.getWeight()*(edge.getMlenght()/static_cast<double>(100)));

    }
}
