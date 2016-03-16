#include "PheromonWeight.hpp"



void PheromonWeight::leavePheromon(WeightGraph &mGraph, Edge mE){
    mGraph.changeEdgeWeight(mGraph.edge(mE), 5);
}
