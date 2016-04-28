#include "WeightGraph.hpp"

void WeightGraph::append(const Edge &mE)
{
    if(!this->isEdgeInGraph(mE))
        push_back(mE);
    else ; //do nothing
}

bool WeightGraph::isEdgeInGraph(const Edge &mE) const
{
    for(auto edge: *this){
        if(edge==mE){
            return true;
        }
    }
    return false;
}
 void WeightGraph::changeEdgeWeight(Edge &mE,int mW)
{
    mE.incrementWeight(mW);
}

std::vector<std::reference_wrapper<Edge>>  WeightGraph::searchNeighbours( Node mN)
{
    std::vector <std::reference_wrapper<Edge>> mNeighbours;
    mNeighbours.clear();
    for(auto& edge:*this){
        if(edge.hasNode(mN)){
            mNeighbours.push_back(std::ref(edge));
        }
    }
    return mNeighbours; //warunek o braku sasiadow?
}


