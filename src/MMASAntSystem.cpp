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
        leavePheromon(mGraph, mAntColony[0].first.getLastPosition(), mAntColony[0].first.position(), 5); //to do
        evaporatePheromon(mGraph);
    }
    while(!isFinalCity());
}

void MMASAntSystem::leavePheromon(WeightGraph &mGraph, Node lastNode, Node position, double w)
{
    static double maxWeight=0.1;/// TODO search initial level of weight
    mGraph.changeEdgeWeight(lastNode, position, maxWeight);
}

void MMASAntSystem::evaporatePheromon(WeightGraph &mGraph)
{
    for(auto& edge:mGraph){
        if(edge.getWeight()>minWeight)
            edge.setWeight(edge.getWeight()-edge.getWeight()*(edge.getMlenght()/static_cast<double>(100)));

    }
}
