#include "IWeightGraph.hpp"
#include <gmock/gmock.h>

class MockWeighGraph : public IWeightGraph
{
public:
	MOCK_METHOD1(createGraph, void(std::vector<BusStop>&));
	MOCK_METHOD1(searchNeighbours, std::vector<std::reference_wrapper<Edge> >(Node));
	MOCK_METHOD2(edge, Edge&(Node, Node));
	MOCK_METHOD3(changeEdgeWeight, void(Node, Node, double));
	
};
