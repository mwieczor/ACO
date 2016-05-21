#include "EltistAntSystem.hpp"

void EltistAntSystem::generateTravel(){
    do{
        for(auto &ant:mAntColony)
        {
            ant.second=ant.first.moveAnt(mGraph.searchNeighbours(ant.first.position()));
            weight.leavePheromon(mGraph, ant.first.getMlastPosition(), ant.first.position());
        }
        sort(mAntColony.begin(), mAntColony.end(), [](const std::pair<Ant, double>&firstAnt, const std::pair<Ant, double>&secondAnt){return firstAnt.second>secondAnt.second;});
       weight.evaporatePheromon(mGraph);
    }
    while(!isFinalCity());
}
