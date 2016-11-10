#include "WeightGraph.hpp"
#include "Edge.hpp"
#include <functional>


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
 void WeightGraph::changeEdgeWeight(Node mN1, Node mN2, double weight) ///SO WRONG
{
     for(auto& edge:*this){
         if(edge.hasNode(mN1) && edge.hasNode(mN2)){
              edge.incrementWeight(weight);
         }
     }

 }

 Edge &WeightGraph::edge(Node mN1, Node mN2) /// It doesn't work properly if there will be one-way road
 {
     for(auto& edge:*this){
         if(edge.hasNode(mN1) && edge.hasNode(mN2)){
              return edge;
         }
     }
 }

std::vector<std::reference_wrapper<Edge>>  WeightGraph::searchNeighbours( Node mN)
{
    std::vector <std::reference_wrapper<Edge>> mNeighbours;
    for(auto& edge:*this){
        if(edge.hasNode(mN)){
            mNeighbours.push_back(std::ref(edge));
        }
    }
    return mNeighbours; //warunek o braku sasiadow?
}


