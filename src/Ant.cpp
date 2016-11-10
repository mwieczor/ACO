#include "Ant.hpp"


bool Ant::wasAntThere(const Edge &E) const
{
    return (E.endNode()==this->getLastPosition() || E.startNode()==this->getLastPosition())?  true: false;
}

void Ant::addEdgeToMemory(const Edge &edge)// lista tabu
{
    whereAntWas.push_back(edge);
}

void Ant::positionToString() const
{

    std::string str =  std::to_string(this->position().coordinate().y());
    std::string strX =  std::to_string(this->position().coordinate().x());
    std::cout<< "Mrówka jest w pkt:"<<strX<< "i y"<<str<< std::endl;
}

void Ant::changePosition(const Node &mN)
{
    mlastPosition = mPosition;
    mPosition = mN;
}

double Ant::moveAnt(std::vector<std::reference_wrapper<Edge>> neighbours)
{
    auto cN=this->getUnvisitedNeighbours(neighbours);
    if(cN.size()>0)
    {
        const auto& bP=BestPosition(cN).calc();
        this->changePosition(bP.endNode());
        return bP.getMlenght();
    }
    else ;///TODO what if ant has no edge to go

}

Node Ant::position() const
{
    return mPosition;
}


Node Ant::getLastPosition() const
{
    return mlastPosition;
}

std::vector<std::reference_wrapper<Edge>> Ant::getUnvisitedNeighbours(std::vector<std::reference_wrapper<Edge>> n){
    std::vector<std::reference_wrapper<Edge>> copyN;
    for(auto edge:n){
        if(!this->wasAntThere(edge))
            copyN.push_back(edge);
    }
    return copyN;
}
