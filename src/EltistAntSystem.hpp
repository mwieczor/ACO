#pragma once
#include "Travel.hpp"
#include <algorithm>
#include "PheromonWeight.hpp"
#include "IEltistAntSystem.hpp"

class Node;

class EltistAntSystem: public PheromonWeight, 
					   public IEltistAntSystem
{
public:
    EltistAntSystem(Node mStart, Node pFinalCity, IWeightGraph &mG):
    startCity(mStart),finalCity(pFinalCity), mGraph(mG){

	}
    double getRouteLenght();
	std::vector<Coordinate> getCalculateRoute();
    Node getFinalCity() const;

    void setFinalCity(const Node &value);

private:
    bool isFinalCity();
	void createAntColony();
	void generateRoute();
    Node startCity;
    Node finalCity;
	IWeightGraph& mGraph;
    double weight =0.1;
    void leaveAdditionalPheromon(Node lastNode, Node mN2);
    std::vector <std::pair<Ant, double>> mAntColony;
     size_t colonySize =10;
     double routeLenght;
	 std::vector<Coordinate> mRoute;
};
