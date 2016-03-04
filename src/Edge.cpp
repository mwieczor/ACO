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
