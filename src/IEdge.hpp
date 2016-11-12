#pragma once

class Node;
class Weight;

class IEdge{
public:
	IEdge(){}
	virtual ~IEdge() = default;
    virtual void setNodes(Node first, Node second) =0;
    virtual Node endNode() const =0;

    virtual Node startNode() const =0;

    virtual void setWeight(const Weight &weight) =0;
    virtual void incrementWeight(const double &mW) =0;

    virtual Node getOtherNode(const Node &mN) const =0;
    virtual bool hasNode(const Node &mN) const =0;

    virtual Weight getWeight() const =0;

    virtual int getLenght() const =0;
};
