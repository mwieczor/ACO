#include "WeightGraph.hpp"

void WeightGraph::append(const Edge &mE)
{
    if(!this->isEdgeInGraph(mE))
        mEdgeCollection.push_back(mE);
    else ; //do nothing
}

bool WeightGraph::isEdgeInGraph(const Edge &mE) const
{
    for(auto edge:mEdgeCollection){
        if(edge.chceckEdges(mE)){
            return true;
        }
    }
    return false;
}

void WeightGraph::changeEdgeWeight(Edge &mE, const Weight &mW)
{
    mE.changeWeight(mW);
}

Edge WeightGraph::searchEdge(const Edge &mE) const
{

}

std::vector<Edge> WeightGraph::searchNeighbours(const Node &mN)
{
    for(auto edge:mEdgeCollection){
        if(edge.hasNode(mN)){
            mNeighbours.push_back(edge);
        }
    }
    return neighbours(); //warunek o braku sasiadow?
}

std::vector<Edge> WeightGraph::edgeCollection() const // nazwa: getGraph?
{
    return mEdgeCollection;
}

std::vector<Edge> WeightGraph::neighbours() const
{
    return mNeighbours;
}

