#include "Travel.hpp"

void Travel::generateTravel(){
    do{
        for(auto &ant:mAntColony)
        {
            ant.moveAnt(mGraph.searchNeighbours(ant.position()));
            weight.leavePheromon(mGraph, ant.getMlastPosition(), ant.position());
        }
       weight.evaporatePheromon(mGraph);
    }
    while(!isFinalCity());
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
    {  if(ant.position()!=getFinalCity())
            return false;

    }
    return true;
}
