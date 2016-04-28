#pragma once

#include "WeightGraph.hpp"
#include <boost/optional.hpp>
#include <cmath>
#include <iostream>

class Ant{
public:
    Ant(){}
    Ant(Coordinate antC):
        mCoordinate(antC){} // czy potrzebne? ///NOTE BW, tak
    Ant(Node mN):
        mPosition(mN){}



    void moveAnt(std::vector<std::reference_wrapper<Edge> > neighbours); //krok 2. poruszam mrowka i zostawiam feromon

    Node position() const;
    void setPosition(const Node &position); // krok 1. Ustawiam mrowke na starcie
    Node getMlastPosition() const;

    void positionToString() const;

    Edge getBestPosition() const;

private:
    boost::optional <Edge> choosePath(std::vector<std::reference_wrapper<Edge> > neighbour );
    bool wasAntThere(const Edge& E) const;
    double probabilityNodeChosen(const Edge &E);
    boost::optional<Edge> chooseBestPosition(const std::vector<std::reference_wrapper<Edge>> &neighbours) const;
    void calculateProbability();
    void addEdgeToMemory (const Edge &edge);
    int bestProbabilityPosition() const;
    void changePosition(const Node &mN);

    ///NOTE BW do przechowywania pozycji masz inną zmienną,
    /// zrzutuj Coordinate antC na Node i to zapisz w mPosition
    Coordinate mCoordinate;

    Node mPosition;
    Node mlastPosition;
    double mProbability=0;
    double mNodeProbability=0;
    std::vector<double> nodeProbability;
    std::vector<Edge> whereAntWas;
    boost::optional<Edge> bestPosition;


};
