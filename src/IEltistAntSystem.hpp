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
    virtual void generateRoute() =0;
    virtual double getRouteLenght() =0;
    virtual void createAntColony() =0;

    virtual Node getFinalCity() const =0;

    virtual void setFinalCity(const Node &value) =0;
};
