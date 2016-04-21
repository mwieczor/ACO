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

//Edge &WeightGraph::edge(const Edge &mE)
//{
//    for(auto &edge:*this){
//        if(edge==mE){
//            return edge;
//        }
//    }
//}

std::vector<Edge &> WeightGraph::searchNeighbours(const Node &mN)
{
    std::vector <Edge &> mNeighbours;
    mNeighbours.clear();
    for(auto &edge:*this){
        if(edge.hasNode(mN)){
            mNeighbours.push_back(edge);
        }
    }
    return mNeighbours; //warunek o braku sasiadow?
}


