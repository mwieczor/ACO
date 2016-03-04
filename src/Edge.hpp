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

    Node endNode() const;

    Node startNode() const;

private:
    Node mStartNode;
    Node mEndNode;
    Weight mWeight;

};


