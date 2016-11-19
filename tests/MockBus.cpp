#include "IBus.hpp"
#include <gmock/gmock.h>

class MockBus: public  IBus
{
public:
	MockBus(){}
	MOCK_CONST_METHOD0(getPosition, Coordinate());
	MOCK_METHOD1(ride, void(Coordinate));
	MOCK_METHOD1(releaseSeat, void(int));
    MOCK_CONST_METHOD0(getNbOfPassengers, int());
    MOCK_METHOD1(increasePassengersNumber, void(int));
};
