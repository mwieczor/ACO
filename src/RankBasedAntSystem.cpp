#include "RankBasedAntSystem.hpp"

void RankBasedAntSystem::setStartGraphWeight()
{
    for(auto &edge:mGraph)
        edge.incrementWeight(1/edge.getMlenght());

}

void RankBasedAntSystem::generateRoute()
{
    do{
        for(auto &ant:mAntColony)
        {
            ant.second=ant.first.moveAnt(mGraph.searchNeighbours(ant.first.position()));
            weight.leavePheromon(mGraph, ant.first.getMlastPosition(), ant.first.position());
        }

        weight.evaporatePheromon(mGraph);
    }
    while(!isFinalCity());
}
