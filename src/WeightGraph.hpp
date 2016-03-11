#pragma once

#include <vector>

#include "Edge.hpp"

class WeightGraph{
public:
    WeightGraph(){} ///NOTE reprezentacja grafu doczytac
    void append(const Edge &mE);
    bool isEdgeInGraph(const Edge &mE) const;
    void changeEdgeWeight(Edge &mE, int mW);
    Edge edge(const Edge &mE)  const;

    ///NOTE BW Jeżeli nie planujesz zmieniać obiektu (patrz, NOTE w definicji) zmień na const
    std::vector <Edge> searchNeighbours(const Node &mN);

    std::vector<Edge> edgeCollection() const;

    ///NOTE BW funkcja do usunięcia (lub zmieny na getLastNeighbours, wtedy nie byłoby to mylące)
    std::vector<Edge> neighbours() const;

private:
    int mNodesNumber;
    std::vector <Edge> mEdgeCollection;

    ///NOTE BW Zmienna do usunięcia, przechowujesz w niej tymczasowe dane, takie trzymaj w funkcji
    /// tzn twórz zmienną w funkcji, i tą zmienną zwracaj
    std::vector <Edge> mNeighbours;
};
