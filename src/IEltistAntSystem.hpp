#pragma once
#include "Travel.hpp"
#include <algorithm>
#include "PheromonWeight.hpp"

class Node;
class WeightGraph;

class IEltistAntSystem
{
public:
    IEltistAntSystem(){}
	virtual ~IEltistAntSystem() = default;
    virtual double getRouteLenght() =0;
	virtual std::vector<std::pair<Coordinate, int>> getCalculateRoute() =0;
	virtual Node getFinalCity() const =0;
    virtual void setFinalCity(const Node &value) =0;
};
