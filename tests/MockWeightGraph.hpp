#include "IWeightGraph.hpp"
#include <gmock/gmock.h>

class MockWeighGraph : public IWeightGraph
{
public:
	MOCK_METHOD1(createGraph, void(std::vector<BusStop>&));
	
};
