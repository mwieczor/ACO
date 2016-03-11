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

    Edge choosePath(const std::vector<Edge> &neighbour );

    void changePosition(const Node &mN);

    void moveAnt(const std::vector<Edge> &neighbours); //krok 2. poruszam mrowka i zostawiam feromon

    Node position() const;
    void setPosition(const Node &position); // krok 1. Ustawiam mrowke na starcie
    Node getMlastPosition() const;

    int getPhermonon() const;

private:
    void leavePheromon(Edge &bestPosition); //niepotrzebne?
    bool wasAntThere(const Edge &E);
    double probabilityNodeChosen(const Edge &E);
    Edge chooseBestPosition(const std::vector<Edge> &neighbours);
    void calculateProbability();
    void addEdgeToMemory (const Edge &edge);
    int bestProbabilityPosition();


    Edge edge;
    Coordinate mCoordinate;
    int phermonon; //wartosc stala?
    Node mPosition;
    Node mlastPosition;
    double mProbability=0;
    double mNodeProbability=0;
    std::vector<double> nodeProbability;
    std::vector<Edge> whereAntWas;

};
