#include "Travel.hpp"

void Travel::generateTravel(){
    do{
        for(auto &ant:mAntColony)
        {
            ant.moveAnt(mGraph.searchNeighbours(ant.position()));
            //weight.leavePheromon(mGraph, ant.getBestPosition());
        }
        weight.evaporatePheromon(mGraph);
    }
    while(!isFinalCity());

    //    Ant test;
    //    test.setPosition(startCity);
    //    while(test.position()!=finalCity){
    //        test.positionToString();
    //        test.moveAnt(mGraph.searchNeighbours(test.position()));

    //    }
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
            test.setPosition(startCity);
            while(test.position()!=finalCity){
                //test.positionToString();
                test.moveAnt(mGraph.searchNeighbours(test.position()));/// TODO do sth with getBest position from ANT
                //routeLenght=routeLenght+test.getBestPosition().getMlenght();

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
