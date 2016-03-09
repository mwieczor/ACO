#pragma once

#include "WeightGraph.hpp"
#include <cmath>

class Ant{
public:
    Ant(){}
    Ant(Coordinate antC):
        mCoordinate(antC){} // czy potrzebne?

    Ant(Node mN):
        mPosition(mN){}

    Node choosePath(const std::vector<Edge> &neighbour );

    void changePosition(const Node &mN);



    Node position() const;
    void setPosition(const Node &position);
    Node getMlastPosition() const;

    int getPhermonon() const;

private:
    void leavePheromon(); //niepotrzebne
    bool wasAntThere(const Edge &E);
    double probabilityNodeChosen(const Edge &E);
    Node chooseNode(const std::vector<Edge> &n) const;
    void calculateProbability();



    Edge edge;
    Coordinate mCoordinate;
    int phermonon; //wartosc stala?
    Node mPosition;
    Node mlastPosition;
    double mProbability=0;
    double mNodeProbability=0;
    std::vector<double> nodeProbability;

};
