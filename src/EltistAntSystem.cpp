#include "EltistAntSystem.hpp"
#include "Edge.hpp"

void EltistAntSystem::generateRoute(){
    do{
        for(auto &ant:mAntColony)
        {
            ant.second=ant.first.moveAnt(mGraph.searchNeighbours(ant.first.position()));
            leavePheromon(mGraph, ant.first.getLastPosition(), ant.first.position(), weight);
        }
        sort(mAntColony.begin(), mAntColony.end(),
             [](const std::pair<Ant, double>&firstAnt, const std::pair<Ant, double>&secondAnt)
                                                    {return firstAnt.second>secondAnt.second;});
        leaveAdditionalPheromon(mAntColony[0].first.getLastPosition(), mAntColony[0].first.position());
        evaporatePheromon(mGraph);
    }
    while(!isFinalCity());
}

void EltistAntSystem::leaveAdditionalPheromon(Node lastNode, Node mN2){
    mGraph.changeEdgeWeight(lastNode, mN2, weight);
}


double  EltistAntSystem::getRouteLenght()
{
    std::unique_ptr<Ant> test =  std::make_unique<Ant> (startCity);
    routeLenght=0;
            while(test->position()!=finalCity){
                test->positionToString();
                test->moveAnt(mGraph.searchNeighbours(test->position()));/// TODO do sth with getBest position from ANT
                if(test->getLastPosition() != test->position())
                    routeLenght+=mGraph.edge(test->getLastPosition(), test->position()).getLenght();

            }
			return routeLenght;
}

std::vector<Coordinate> EltistAntSystem::getCalculateRoute()
{
	createAntColony();
	generateRoute();
	return mRoute;
	
}

void EltistAntSystem::createAntColony()
{
    while(mAntColony.size()<colonySize)
        mAntColony.push_back(std::make_pair(Ant(startCity),0));

}

bool EltistAntSystem::isFinalCity()
{
    for(auto ant:mAntColony)
    {  if(ant.first.position()!=getFinalCity())
            return false;

    }
    return true;

}

void EltistAntSystem::setFinalCity(const Node &value)
{
    finalCity = value;
}

Node EltistAntSystem::getFinalCity() const
{
    return finalCity;
}
