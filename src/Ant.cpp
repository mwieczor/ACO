#include "Ant.hpp"

void Ant::leavePheromon()
{
    edge.setNodes(getMlastPosition(),position());
    // WeightGraph::changeEdgeWeight(WeightGraph::edge(edge), phermonon);
}

bool Ant::wasAntThere(const Edge &E)
{
    return (E.endNode()==this->getMlastPosition() || E.startNode()==this->getMlastPosition())?  true: false;
}

double Ant::probabilityNodeChosen(const Edge &E)// niepotrzebna zmienna mNodeProbabilty?
{
    mNodeProbability=0;
    mNodeProbability=std::pow(E.getWeight().weight(), 0.5) * std::pow(std::pow(E.getMlenght(),-1),0.5);
    mProbability=mProbability+mNodeProbability;
    return mNodeProbability;

}

Node Ant::chooseNode(const std::vector<Edge> &n) const //zrobic iteratorem?
{
    double max=-1;
    int maxPosition=-1;
    for (int i=0; i<nodeProbability.size(); i++){
        if(max<nodeProbability.at(i))
            maxPosition=i;
            max=nodeProbability.at(i);
    }
    return n.at(maxPosition).endNode(); //czy na pewno end?
}

void Ant::calculateProbability()
{
    for (int i=0; i<nodeProbability.size(); i++){
        nodeProbability.at(i)=nodeProbability.at(i)/mProbability;
    }
}

int Ant::getPhermonon() const
{
    return phermonon;
}

Node Ant::choosePath(const std::vector<Edge> &neighbour)
{
    mProbability=0; //czyscimy prawdopodobienstwo dla nowych sąsiadów
    nodeProbability.clear();
    for(auto edge:neighbour){
        if(!this->wasAntThere(edge)){
            nodeProbability.push_back(this->probabilityNodeChosen(edge));
        }
    }
    calculateProbability();
    return chooseNode(neighbour);

}

void Ant::changePosition(const Node &mN)
{
    mlastPosition=mPosition; //jak to jest z notacja? uzywac zmiennych czy funkcji doostepowych do zmiennych?
    this->setPosition(mN);
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
