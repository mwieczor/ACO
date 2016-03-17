#include "Ant.hpp"

#include <cmath>
#include <iostream>

void Ant::leavePheromon(Edge &bestPosition)
{
    bestPosition.incrementWeight(this->getPhermonon());
}

bool Ant::wasAntThere(const Edge &E) const
{
    return (E.endNode()==this->getMlastPosition() || E.startNode()==this->getMlastPosition())?  true: false;
}

double Ant::probabilityNodeChosen(const Edge &E)
{
    mNodeProbability=0;
    mNodeProbability=std::pow(E.getWeight().weight(), 0.5) * std::pow(std::pow(E.getMlenght(),-1),0.5);
    mProbability=mProbability+mNodeProbability;
    return mNodeProbability;

}

Edge Ant::chooseBestPosition(const std::vector<Edge> &neighbours) const
{ 
    return neighbours.at(bestProbabilityPosition());
}

void Ant::calculateProbability()
{
    for (int i=0; i<nodeProbability.size(); i++){
        nodeProbability.at(i)=nodeProbability.at(i)/mProbability;
    }
}

void Ant::addEdgeToMemory(const Edge &edge)// lista tabu
{
    whereAntWas.push_back(edge);
}

int Ant::bestProbabilityPosition() const
{
    double max=0;
    int bestPosition=0;
    for (int i=0; i<nodeProbability.size(); i++){
        if(max<nodeProbability.at(i)) // what if there are two the same node's probability?
            bestPosition=i;
        max=nodeProbability.at(i);
    }
    return bestPosition;
}

Edge Ant::getBestPosition() const
{
    return bestPosition.get();
}


int Ant::getPhermonon() const
{
    return phermonon;
}

void Ant::positionToString() const
{

    std::string str =  std::to_string(this->position().coordinate().y());
    std::string strX =  std::to_string(this->position().coordinate().x());
    std::cout<< "Mrówka jest w pkt:"<<strX<< "i y"<<str;
}

boost::optional<Edge> Ant::choosePath(const std::vector<Edge> &neighbour)
{

    mProbability=0; //czyscimy prawdopodobienstwo dla nowych sąsiadów
    nodeProbability.clear();
    std::vector <Edge> copyNeighbour; //do it better
    for(auto edge:neighbour){
        if(!this->wasAntThere(edge)){
            nodeProbability.push_back(this->probabilityNodeChosen(edge));
            copyNeighbour.push_back(edge);
        }
    }
    if(nodeProbability.size()!=0){
        this->calculateProbability();
        return chooseBestPosition(copyNeighbour);
    }

    return boost::none;

}

void Ant::changePosition(const Node &mN)
{
    mlastPosition=mPosition; //jak to jest z notacja? uzywac zmiennych czy funkcji doostepowych do zmiennych?
    this->setPosition(mN);
}

void Ant::moveAnt(const std::vector<Edge> &neighbours)
{
    if(neighbours.size()>0){

        bestPosition=this->choosePath(neighbours);
        if( bestPosition.is_initialized()){
            this->changePosition(bestPosition->endNode());
        }
    }

}

Node Ant::position() const
{
    return mPosition;
}

void Ant::setPosition(const Node &position)
{
    mPosition = position;
}

Node Ant::getMlastPosition() const
{
    return mlastPosition;
}
 int Ant::phermonon=5;
