#include "Ant.hpp"



bool Ant::wasAntThere(const Edge &E) const
{
    return (E.endNode()==this->getMlastPosition() || E.startNode()==this->getMlastPosition())?  true: false;
}

double Ant::probabilityNodeChosen(const Edge &E)
{
    mNodeProbability=0;
    mNodeProbability=std::pow(E.getWeight(), 0.5) * std::pow(std::pow(E.getMlenght(),-1),0.5);
    mProbability=mProbability+mNodeProbability;
    return mNodeProbability;

}

boost::optional<Edge> Ant::chooseBestPosition(const std::vector<std::reference_wrapper<Edge>> &neighbours) const
{
    if(bestProbabilityPosition()!=-1)
    {
        int i= bestProbabilityPosition();
        return neighbours.at(i).get();
    }
        else return boost::none;
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
    std::srand(time(NULL));
    double max=0;
    int bestPosition=0;
    double random = 0.5; //poprawic

    for (int i=0; i<nodeProbability.size(); i++){
        if(max<nodeProbability.at(i)) // what if there are two the same node's probability?
            bestPosition=i;
        max=nodeProbability.at(i);
    }
    if(max>=random){
       return bestPosition;  //ant moves randomly
    }
    else return -1; //do it diffrent
}

Edge Ant::getBestPosition() const
{
    return bestPosition.get();
}


void Ant::positionToString() const
{

    std::string str =  std::to_string(this->position().coordinate().y());
    std::string strX =  std::to_string(this->position().coordinate().x());
    std::cout<< "Mrówka jest w pkt:"<<strX<< "i y"<<str;
}

boost::optional<Edge> Ant::choosePath(std::vector<std::reference_wrapper<Edge>> neighbour)
{

    mProbability=0; //czyscimy prawdopodobienstwo dla nowych sąsiadów
    nodeProbability.clear();
    std::vector <std::reference_wrapper<Edge>> copyNeighbour;
    for(auto edge:neighbour){
        if(!this->wasAntThere(edge)){
            nodeProbability.push_back(this->probabilityNodeChosen(edge));
            copyNeighbour.push_back(edge);
        }
    }
    if(nodeProbability.size()!=0){
        this->calculateProbability();

        if(chooseBestPosition(copyNeighbour)!=boost::none) ///it makes no sense,do it better
            return boost::none;
        else return chooseBestPosition(copyNeighbour);
    }

    return boost::none;

}

void Ant::changePosition(const Node &mN)
{
    mlastPosition=mPosition;
    this->setPosition(mN);
}

void Ant::moveAnt(std::vector<std::reference_wrapper<Edge>> neighbours)
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


