#pragma once

#include "WeightGraph.hpp"
#include <boost/optional.hpp>

class Ant{
public:
    Ant(){}
    Ant(Coordinate antC):
        mCoordinate(antC){} // czy potrzebne? ///NOTE BW, tak
    Ant(Node mN):
        mPosition(mN){}



    void changePosition(const Node &mN);

    void moveAnt(const std::vector<Edge> &neighbours); //krok 2. poruszam mrowka i zostawiam feromon

    Node position() const;
    void setPosition(const Node &position); // krok 1. Ustawiam mrowke na starcie
    Node getMlastPosition() const;

    ///NOTE BW pamiętasz o klasie PheromonWeight ??
    int getPhermonon() const;



    Edge getBestPosition() const;

private:
    boost::optional <Edge> choosePath(const std::vector<Edge> &neighbour );
    void leavePheromon(Edge &bestPosition); //niepotrzebne?
    bool wasAntThere(const Edge &E) const;
    double probabilityNodeChosen(const Edge &E);
    Edge chooseBestPosition(const std::vector<Edge> &neighbours) const;
    void calculateProbability();
    void addEdgeToMemory (const Edge &edge);
    int bestProbabilityPosition() const;

    ///NOTE BW do przechowywania pozycji masz inną zmienną,
    /// zrzutuj Coordinate antC na Node i to zapisz w mPosition
    Coordinate mCoordinate;

    ///NOTE BW pamiętasz o klasie PheromonWeight ??
    static int phermonon; //wartosc stala?
    Node mPosition;
    Node mlastPosition;
    double mProbability=0;
    double mNodeProbability=0;
    std::vector<double> nodeProbability;
    std::vector<Edge> whereAntWas;
    boost::optional<Edge> bestPosition;

};
