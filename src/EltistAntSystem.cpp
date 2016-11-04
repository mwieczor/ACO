#include "EltistAntSystem.hpp"

void EltistAntSystem::generateRoute(){
    do{
        for(auto &ant:mAntColony)
        {
            ant.second=ant.first.moveAnt(mGraph.searchNeighbours(ant.first.position()));
            leavePheromon(mGraph, ant.first.getLastPosition(), ant.first.position(), weight);
        }
        sort(mAntColony.begin(), mAntColony.end(),
             [](const std::pair<Ant, double>&firstAnt, const std::pair<Ant, double>&secondAnt)
                                                    {return firstAnt.second>secondAnt.second;});
        leaveAdditionalPheromon(mAntColony[0].first.getLastPosition(), mAntColony[0].first.position());
        evaporatePheromon(mGraph);
    }
    while(!isFinalCity());
}

void EltistAntSystem::leaveAdditionalPheromon(Node lastNode, Node mN2){
    mGraph.changeEdgeWeight(lastNode, mN2, weight);
}

