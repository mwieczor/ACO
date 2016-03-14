#include "Edge.hpp"

void Edge::setNodes(Node first, Node second)
{
    mStartNode=first;
    mEndNode=second;
}

bool Edge::chceckEdges(const Edge &mE) const //po co skoro mam operator == ?
{
   return *this==mE;
}

Node Edge::endNode() const
{
    return mEndNode;
}

Node Edge::startNode() const
{
    return mStartNode;
}

void Edge::setWeight(const Weight &weight)
{
    mWeight = weight;
}

void Edge::incrementWeight(const int &mW)
{
    this->setWeight(this->mWeight.weight()+mW);
}

Node Edge::getOtherNode(const Node &mN) const
{
    if(mN==this->startNode())
        return this->endNode();
    else return this->startNode();
}

bool Edge::hasNode(const Node &mN) const
{
    (mN==this->endNode() || mN==this->startNode())? true : false;
}

Weight Edge::getWeight() const
{
    return mWeight;
}

int Edge::getMlenght() const
{
    return mlenght;
}

int Weight::weight() const
{
    return mWeight;
}
