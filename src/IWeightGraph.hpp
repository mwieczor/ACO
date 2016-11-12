#pragma once

#include <vector>

class Edge;
class Node;

class IWeightGraph: public std::vector<Edge>{
public:
    IWeightGraph(){} 
    virtual void append(const Edge &mE) =0;
    virtual bool isEdgeInGraph(const Edge &mE) const =0;
    virtual void changeEdgeWeight(Node mN1, Node mN2, double weight) =0;
    virtual Edge& edge(Node mN1, Node mN2) =0;
    virtual std::vector<std::reference_wrapper<Edge> > searchNeighbours(Node mN) =0;
	virtual ~IWeightGraph() = default;

};
