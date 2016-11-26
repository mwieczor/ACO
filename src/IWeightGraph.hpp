#pragma once

#include <vector>

#include "Edge.hpp"
class Node;
class BusStop;

class IWeightGraph: public std::vector<Edge>{
public:
    IWeightGraph(){} 
    virtual void changeEdgeWeight(Node mN1, Node mN2, double weight) =0;
    virtual Edge& edge(Node mN1, Node mN2) =0;
    virtual std::vector<std::reference_wrapper<Edge> > searchNeighbours(Node mN) =0;
	virtual void createGraph(std::vector<BusStop>&) =0;
	virtual ~IWeightGraph() = default;

};
