#pragma once

#include "IAnt.hpp"
#include "WeightGraph.hpp"
#include "BestPosition.hpp"
#include <boost/optional.hpp>
#include <cmath>
#include <iostream>
#include <memory>
#include "Edge.hpp"

class BestPosition;


class Ant: public IAnt
{
public:
    Ant(){}
    Ant(Node mN):
        mPosition(mN){}
    double moveAnt(std::vector<std::reference_wrapper<Edge> > neighbours) override;
    Node position() const;
    Node getLastPosition() const override ;
    void positionToString() const override;
	
private:
    bool wasAntThere(const Edge& E) const;
    void addEdgeToMemory (const Edge &edge);
    void changePosition(const Node &mN);
    std::vector<std::reference_wrapper<Edge> > getUnvisitedNeighbours(std::vector<std::reference_wrapper<Edge>> n);

    Node mPosition;
    Node mlastPosition;
    double mProbability=0;
    double mNodeProbability=0;
    std::vector<double> nodeProbability;
    std::vector<Edge> whereAntWas;
    std::shared_ptr<BestPosition> bestPosition;


};
