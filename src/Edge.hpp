#pragma once

#include "Node.hpp"
#include "IEdge.hpp"

class Weight{
public :
    Weight():
        mWeight(){}
    Weight(double mW):
        mWeight(mW){}
    bool operator==(const Weight &mW) const {
        return this->mWeight==mW.mWeight;
    }

   operator double(){
        return mWeight;
    }

private:
    double mWeight;
};

class Edge: public IEdge{
public:
    Edge():
        mWeight(0){}///NOTE jaka wartosc poczatkowa feromonu?
    Edge(Node start, Node end):
        mStartNode(start), mEndNode(end), mWeight(0){} //do testow
    Edge(Node start, Node end, int lenght, Weight mW):
        mStartNode(start), mEndNode(end), mWeight(mW), mlenght(lenght){}
    void setNodes(Node first, Node second);
    bool operator==(const Edge &other) const{
        return other.mStartNode==this->mStartNode &&
                other.mEndNode==this->mEndNode &&
                other.mWeight==this->mWeight; ///NOTE zakladamy, ze moga byc rozne krawdzeie laczace dwa pkt
    }

    Node endNode() const;

    Node startNode() const;
    Node &getNode(Node pN);
    void setWeight(const Weight &weight);
    void incrementWeight(const double &mW);

    Node getOtherNode(const Node &mN) const;
    bool hasNode(const Node &mN) const;

    Weight getWeight() const;

    int getLenght() const;

private:
    Node mStartNode;
    Node mEndNode;
    Weight mWeight;
    int mlenght; //dlugosc trasy

};


