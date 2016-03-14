#include "Ant.hpp"

#include <cmath>

void Ant::leavePheromon(Edge &bestPosition) const
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
    double max=-1;
    int bestPosition=-1;
    for (int i=0; i<nodeProbability.size(); i++){
        if(max<nodeProbability.at(i))
            bestPosition=i;
        max=nodeProbability.at(i);
    }
    return bestPosition;
}

int Ant::getPhermonon() const
{
    return phermonon;
}

boost::optional<Edge> Ant::choosePath(const std::vector<Edge> &neighbour)
{

    mProbability=0; //czyscimy prawdopodobienstwo dla nowych sąsiadów
    nodeProbability.clear();
    for(auto edge:neighbour){
        if(!this->wasAntThere(edge)){
            nodeProbability.push_back(this->probabilityNodeChosen(edge));
        }
    }
    if(nodeProbability.size()!=0){
        this->calculateProbability();
        return chooseBestPosition(neighbour);
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

        auto bestPosition=this->choosePath(neighbours);
        if( bestPosition.is_initialized()){
            this->changePosition(bestPosition->endNode());
            this->leavePheromon(bestPosition.get()); // zostawiam feromon na krawedzi, ktora przeszla
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
