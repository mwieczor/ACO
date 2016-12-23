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
    EltistAntSystem(){
        mGraph = std::make_shared<WeightGraph>();
    }
    double getRouteLenght();
	std::vector<std::pair<Coordinate, int>> getCalculateRoute();
    Node getFinalCity() const;

    void setFinalCity(Coordinate);

	void setStartCity(Coordinate);
	
    void setGraph(const IWeightGraph & graph);
	
private:
	bool isFinalCity();
	void createAntColony();
	void generateRoute();
    Node startCity;
    Node finalCity;
    std::shared_ptr<IWeightGraph> mGraph;
    double weight =0.1;
    void leaveAdditionalPheromon(Node lastNode, Node mN2);
    std::vector <std::pair<Ant, double>> mAntColony;
     size_t colonySize =10;
     double routeLenght;
	 std::vector<std::pair<Coordinate, int>> mRoute;
};
