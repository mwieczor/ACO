#pragma once

#include <vector>
#include <functional>

#include "Edge.hpp"

class WeightGraph: public std::vector<Edge>{
public:
    WeightGraph(){

    } ///NOTE reprezentacja grafu doczytac
    void append(const Edge &mE);
    bool isEdgeInGraph(const Edge &mE) const;
    void changeEdgeWeight(Node mN1, Node mN2);
    Edge& edge(Node mN1, Node mN2);

    std::vector<std::reference_wrapper<Edge> > searchNeighbours(Node mN);




private:

    int mNodesNumber;


};
