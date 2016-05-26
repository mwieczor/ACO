#include "MMASAntSystem.hpp"


void MMASAntSystem::setStartGraphWeight()
{
    maxWeight=1;
    for(auto &edge:mGraph)
        edge.incrementWeight(maxWeight);
}

void MMASAntSystem::generateRoute()
{
    do{
        for(auto &ant:mAntColony)
        {
            ant.second=ant.first.moveAnt(mGraph.searchNeighbours(ant.first.position()));

        }
        sort(mAntColony.begin(), mAntColony.end(),
             [](const std::pair<Ant, double>&firstAnt, const std::pair<Ant, double>&secondAnt)
                                                    {return firstAnt.second>secondAnt.second;});
        weight.leavePheromon(mGraph, mAntColony[0].first.getMlastPosition(), mAntColony[0].first.position());
        weight.evaporatePheromon(mGraph);
    }
    while(!isFinalCity());
}
