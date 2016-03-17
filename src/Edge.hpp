#pragma once

#include "Node.hpp"

class Weight{
public :
    Weight():
        mWeight(){}
    Weight(double mW):
        mWeight(mW){}
    bool operator==(const Weight &mW) const {
        return this->mWeight==mW.mWeight;
    }

    double weight() const;

private:
    double mWeight;
};

class Edge{
public:
    Edge():
        mWeight(){}///NOTE jaka wartosc poczatkowa feromonu?
    Edge(Node start, Node end):
        mStartNode(start), mEndNode(end), mWeight(){} //do testow
    Edge(Node start, Node end, int lenght, Weight mW):
        mStartNode(start), mEndNode(end), mWeight(mW), mlenght(lenght){}
    void setNodes(Node first, Node second);
    bool operator==(const Edge &other) const{
        return other.mStartNode==this->mStartNode && other.mEndNode==this->mEndNode && other.mWeight==this->mWeight; ///NOTE zakladamy, ze moga byc rozne krawdzeie laczace dwa pkt
    }
    bool chceckEdges(const Edge &mE) const;

    Node endNode() const;

    Node startNode() const;

    void setWeight(const Weight &weight);
    void incrementWeight(const int &mW);

    Node getOtherNode(const Node &mN) const;
    bool hasNode(const Node &mN) const;

    Weight getWeight() const;

    int getMlenght() const;

private:
    Node mStartNode;
    Node mEndNode;
    Weight mWeight;
    int mlenght; //dlugosc trasy

};


