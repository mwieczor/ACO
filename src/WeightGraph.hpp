#pragma once


#include "IWeightGraph.hpp"

class WeightGraph: public IWeightGraph
{
public:
    WeightGraph(){

    } ///NOTE reprezentacja grafu doczytac
    void createGraph(std::vector<BusStop> &);
    void changeEdgeWeight(Node mN1, Node mN2, double weight);
    Edge& edge(Node mN1, Node mN2);
    std::vector<std::reference_wrapper<Edge> > searchNeighbours(Node mN);



private:
	bool isEdgeInGraph(const Edge &mE) const;
	void append(const Edge &mE);
    int mNodesNumber;
	Node &searchNode(Node pN);
};
