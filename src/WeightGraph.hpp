#pragma once

#include <vector>

#include "Edge.hpp"

class WeightGraph{
public:
    WeightGraph(){} ///NOTE reprezentacja grafu doczytac
    void append(const Edge &mE);
    bool isEdgeInGraph(const Edge &mE) const;
    void changeEdgeWeight(Edge &mE, int mW);
    Edge &edge(const Edge &mE);

    std::vector <Edge> searchNeighbours(const Node &mN) const;

    std::vector<Edge> edgeCollection() const;

private:
    int mNodesNumber;
    std::vector <Edge> mEdgeCollection;

};
