#include "Edge.hpp"

void Edge::setNodes(Node first, Node second)
{
    mStartNode=first;
    mEndNode=second;
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

void Edge::incrementWeight(const double &mW)
{
    this->setWeight(this->mWeight+(1/mW));
}

Node Edge::getOtherNode(const Node &mN) const
{
    if(mN==this->startNode())
        return this->endNode();
    else return this->startNode();
}

bool Edge::hasNode(const Node &mN) const
{
   return (mN==this->endNode() || mN==this->startNode())? true : false;
}

Weight Edge::getWeight() const
{
    return mWeight;
}

int Edge::getMlenght() const
{
    return mlenght;
}

