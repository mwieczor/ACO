#include "AntColony.hpp"


void AntColony::generateRoute()
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
