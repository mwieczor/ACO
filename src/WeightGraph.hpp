#pragma once


#include "IWeightGraph.hpp"

class WeightGraph: public IWeightGraph
{
public:
    WeightGraph(){

    } ///NOTE reprezentacja grafu doczytac
    void append(const Edge &mE);
    bool isEdgeInGraph(const Edge &mE) const;
    void changeEdgeWeight(Node mN1, Node mN2, double weight);
    Edge& edge(Node mN1, Node mN2);

    std::vector<std::reference_wrapper<Edge> > searchNeighbours(Node mN);




private:

    int mNodesNumber;


	
	// IWeightGraph interface
public:
	void createGraph(std::vector<BusStop> &);
};
