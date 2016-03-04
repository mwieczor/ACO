#include "WeightGraph.hpp"

void WeightGraph::append(const Edge &mE)
{
    if(!this->isEdgeInGraph(mE))
    mEdgeCollection.push_back(mE);
}

bool WeightGraph::isEdgeInGraph(const Edge &mE)
{
    for(auto it:mEdgeCollection){
       if(it.chceckEdges(mE)){
           return false;
       }
    }
    return true;
}

std::vector<Edge> WeightGraph::edgeCollection() const
{
    return mEdgeCollection;
}
