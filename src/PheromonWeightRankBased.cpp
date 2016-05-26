#include "PheromonWeightRankBased.hpp"


void PheromonWeightRankBased::leavePheromon(WeightGraph &mGraph, Node lastNode, Node position)
{
    mGraph.changeEdgeWeight(lastNode, position,1/mGraph.edge(lastNode, position).getMlenght());
}
