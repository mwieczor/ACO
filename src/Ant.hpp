#pragma once

#include "WeightGraph.hpp"
#include "BestPosition.hpp"
#include <boost/optional.hpp>
#include <cmath>
#include <iostream>
#include <memory>

class BestPosition;

class Ant{
public:
    Ant(){}
    Ant(Coordinate antC):
        mCoordinate(antC){} // czy potrzebne? ///NOTE BW, tak
    Ant(Node mN):
        mPosition(mN){}
    double moveAnt(std::vector<std::reference_wrapper<Edge> > neighbours);
    Node position() const;
    void setPosition(const Node &position);
    Node getMlastPosition() const;
    void positionToString() const;
    Edge getBestPosition() const;

private:
    bool wasAntThere(const Edge& E) const;
    void addEdgeToMemory (const Edge &edge);
    void changePosition(const Node &mN);
    std::vector<std::reference_wrapper<Edge> > getUnvisitedNeighbours(std::vector<std::reference_wrapper<Edge>> n);
    ///NOTE BW do przechowywania pozycji masz inną zmienną,
    /// zrzutuj Coordinate antC na Node i to zapisz w mPosition
    Coordinate mCoordinate;

    Node mPosition;
    Node mlastPosition;
    double mProbability=0;
    double mNodeProbability=0;
    std::vector<double> nodeProbability;
    std::vector<Edge> whereAntWas;
    std::shared_ptr<BestPosition> bestPosition;


};
