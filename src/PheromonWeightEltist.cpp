#include "PheromonWeightEltist.hpp"


void PheromonWeightEltist::leaveAdditionalPheromon(WeightGraph &mGraph, Node lastNode, Node mN2){
    mGraph.changeEdgeWeight(lastNode, mN2, weight);
}

void PheromonWeightEltist::leavePheromon(WeightGraph &mGraph, Node lastNode, Node position){
    mGraph.changeEdgeWeight(lastNode, position, weight); ///TODO  initial pheromon weight
}
