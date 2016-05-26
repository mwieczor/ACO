#include "PheromonWeightMMAS.h"


void PheromonWeightMMAS::leavePheromon(WeightGraph &mGraph, Node lastNode, Node position){ //only best iteratrion leave pheromon
    mGraph.changeEdgeWeight(lastNode, position, maxWeight);
}
