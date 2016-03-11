#pragma once

#include "WeightGraph.hpp"

///NOTE BW minor: nie potrzebujesz tego tu, przenieś do cppka
#include <cmath>

class Ant{
public:
    Ant(){}
    Ant(Coordinate antC):
        mCoordinate(antC){} // czy potrzebne? ///NOTE BW, tak
    Ant(Node mN):
        mPosition(mN){}

    Edge choosePath(const std::vector<Edge> &neighbour );

    void changePosition(const Node &mN);

    void moveAnt(const std::vector<Edge> &neighbours); //krok 2. poruszam mrowka i zostawiam feromon

    Node position() const;
    ///NOTE BW jeżeli ustawiasz pozycję startową, dlaczego nie nazywasz funkcji setStartPosition
    void setPosition(const Node &position); // krok 1. Ustawiam mrowke na starcie
    Node getMlastPosition() const;

    ///NOTE BW pamiętasz o klasie PheromonWeight ??
    int getPhermonon() const;

private:
    ///NOTE BW minor: funkcja nie modyfikuje this'a, może być const
    void leavePheromon(Edge &bestPosition); //niepotrzebne?
    ///NOTE BW minor: funkcja nie modyfikuje this'a, może być const
    bool wasAntThere(const Edge &E);
    double probabilityNodeChosen(const Edge &E);
    ///NOTE BW minor: funkcja nie modyfikuje this'a, może być const
    Edge chooseBestPosition(const std::vector<Edge> &neighbours);
    void calculateProbability();
    void addEdgeToMemory (const Edge &edge);
    ///NOTE BW minor: funkcja nie modyfikuje this'a, może być const
    int bestProbabilityPosition();

    ///NOTE BW po co jest ta zmienna??
    Edge edge;

    ///NOTE BW do przechowywania pozycji masz inną zmienną,
    /// zrzutuj Coordinate antC na Node i to zapisz w mPosition
    Coordinate mCoordinate;

    ///NOTE BW pamiętasz o klasie PheromonWeight ??
    int phermonon; //wartosc stala?
    Node mPosition;
    Node mlastPosition;
    double mProbability=0;
    double mNodeProbability=0;
    std::vector<double> nodeProbability;
    std::vector<Edge> whereAntWas;

};
