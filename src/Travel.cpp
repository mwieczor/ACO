#include "Travel.hpp"

void Travel::generateTravel(){
    do{
        for(auto ant:mAntColony)
            ant.moveAnt(mGraph.searchNeighbours(ant.position()));
    }
    while(!isFinalCity());

    Ant test;
    test.setPosition(startCity);
    while(test.position()!=finalCity){
        test.positionToString();
        test.moveAnt(mGraph.searchNeighbours(test.position()));

    }
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

void Travel::setStartCity(const Node &value)
{
    startCity = value;
}


int Travel::getRouteLenght() const
{
    return routeLenght;
}

bool Travel::isFinalCity()
{
    for(auto ant:mAntColony)
    {  if(ant.position()!=getFinalCity())
            return false;

    }
    return true;
}
