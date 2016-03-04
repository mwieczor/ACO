#include "Edge.hpp"

void Edge::setNodes(Node first, Node second)
{
    mStartNode=first;
    mEndNode=second;
}

bool Edge::chceckEdges(const Edge &mE)
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
