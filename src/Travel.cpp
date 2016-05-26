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

void Travel::setFinalCity(const Node &value)
{
    finalCity = value;
}

Node Travel::getStartCity() const
{
    return startCity;
}

double Travel::getRouteLenght()
{
    Ant test;
    routeLenght=0;
            test.setPosition(startCity);
            while(test.position()!=finalCity){
                test.positionToString();
                test.moveAnt(mGraph.searchNeighbours(test.position()));/// TODO do sth with getBest position from ANT
                routeLenght+=mGraph.edge(test.getMlastPosition(), test.position()).getMlenght();

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
