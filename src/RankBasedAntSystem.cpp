#include "RankBasedAntSystem.hpp"

void RankBasedAntSystem::setStartGraphWeight()
{
    for(auto &edge:mGraph)
        edge.incrementWeight(1/edge.getLenght());

}

void RankBasedAntSystem::generateRoute()
{
    do{
        for(auto &ant:mAntColony)
        {
            ant.second=ant.first.moveAnt(mGraph.searchNeighbours(ant.first.position()));
            leavePheromon(mGraph, ant.first.getLastPosition(), ant.first.position(), 5); //todo
        }

        evaporatePheromon(mGraph);
    }
    while(!isFinalCity());
}

void RankBasedAntSystem::leavePheromon(WeightGraph &mGraph, Node lastNode, Node position, double weight)
{
      weight= 1/mGraph.edge(lastNode, position).getLenght();
      mGraph.changeEdgeWeight(lastNode, position, weight);
}

