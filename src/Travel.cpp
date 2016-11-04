#include "Travel.hpp"

void Travel::setStartGraphWeight()
{
    for(auto &edge:mGraph)
        edge.incrementWeight(defaultWeight);
}

void Travel::createAntColony()
{
    while(mAntColony.size()<colonySize)
        mAntColony.push_back(std::make_pair(Ant(startCity),0));

}

void Travel::travelToString()
{

}


Node Travel::getFinalCity() const
{
    return finalCity;
}


double Travel::getRouteLenght()
{
    std::unique_ptr<Ant> test =  std::make_unique<Ant> (startCity);
    routeLenght=0;
            while(test->position()!=finalCity){
                test->positionToString();
                test->moveAnt(mGraph.searchNeighbours(test->position()));/// TODO do sth with getBest position from ANT
                if(test->getLastPosition() != test->position())
                    routeLenght+=mGraph.edge(test->getLastPosition(), test->position()).getMlenght();

            }
    return routeLenght;
}

bool Travel::isFinalCity()
{
    for(auto ant:mAntColony)
    {  if(ant.first.position()!=getFinalCity())
            return false;

    }
    return true;
}

void Travel::setFinalCity(const Node &value)
{
    finalCity = value;
}

void Travel::setStartCity(const Node &value)
{
    startCity = value;
}
