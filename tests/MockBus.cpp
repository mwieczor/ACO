#include "IBus.hpp"
#include <gmock/gmock.h>

class MockBus: public  IBus
{
public:
	MockBus(){}
	MOCK_CONST_METHOD0(getPosition, Coordinate());
	MOCK_METHOD1(ride, void(Coordinate));
	MOCK_METHOD1(releaseSeat, void(int));
	MOCK_CONST_METHOD0(getNbOfPassangers, int());
	MOCK_METHOD1(increasePassangersNumber, void(int));
};
