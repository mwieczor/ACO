#include "WeightGraph.hpp"
#include "Edge.hpp"
#include <functional>
#include "Bus.hpp"



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
 void WeightGraph::changeEdgeWeight(Node mN1, Node mN2, double weight)
{
     for(auto& edge:*this){
         if(edge.hasNode(mN1) && edge.hasNode(mN2)){
              edge.incrementWeight(weight);
         }
     }

 }

 Edge &WeightGraph::edge(Node mN1, Node mN2)
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


Node& WeightGraph::searchNode(Node pN)
{
    for(auto& edge:*this){
             if(edge.hasNode(pN)){
                  return edge.getNode(pN);
             }
	}
}

void WeightGraph::createGraph(std::vector<BusStop> & pBusStop)
{
    for(auto s: pBusStop){
        if(s.isDemand){
            auto& temp = searchNode(s.mStop);
            temp.isDemand = true;
        }
    }
}

void WeightGraph::parseData()
{
        for(int i= 4; i<mData.size(); i+=5)
                append(Edge(Node({mData[i-4], mData[i-3]}), Node({mData[i-2], mData[i-1]}), mData[i], {0.1}));
}
