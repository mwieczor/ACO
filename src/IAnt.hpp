#pragma once
#include <vector>
#include <memory>

class Edge;
class Node;

class IAnt{
public:
    IAnt(){}
    virtual double moveAnt(std::vector<std::reference_wrapper<Edge> > neighbours) =0;
    virtual Node getLastPosition() const =0;
    virtual void positionToString() const =0;
	virtual ~IAnt() = default;


};
