#include <gmock/gmock.h>
#include "IEltistAntSystem.hpp"

class MockEltistAntSystem: public IEltistAntSystem{
public:
	MockEltistAntSystem(){}
	MOCK_CONST_METHOD0(getFinalCity, Node());
	MOCK_METHOD1(setFinalCity, void (const Node &));
	MOCK_METHOD0(getRouteLenght, double());
	MOCK_METHOD0(getCalculateRoute, std::vector<std::pair<Coordinate, int>>());
};
