#pragma once

#include "Node.hpp"
#include "PheromonWeight.hpp"

class Weight{
public :
    Weight():
    mWeight(){}
    Weight(int mW):
        mWeight(mW){}

private:
    int mWeight;
};

class Edge{
public:
    Edge():
    mWeight(){}///NOTE jaka wartosc poczatkowa feromonu?
    void setNodes(Node first, Node second);
    bool operator==(const Edge &other) const{
        return other.mStartNode==this->mStartNode && other.mEndNode==this->mEndNode; ///NOTE waga tez musi byc taka sama? czy zakladamy ze skoronody sa rowne to wagi tez?
    }
    bool chceckEdges(const Edge &mE);

    Node endNode() const;

    Node startNode() const;

    void setWeight(const Weight &weight);

private:
    Node mStartNode;
    Node mEndNode;
    Weight mWeight;
    int mlenght; //dlugosc trasy

};


