#include "IBus.hpp"
#include <gmock/gmock.h>

#include "Bus.hpp"

class MockBus: public  IBus
{
public:
	MockBus(){}
	MOCK_CONST_METHOD0(getPosition, Coordinate());
	MOCK_METHOD2(ride, void(Coordinate, Time));
	MOCK_METHOD1(releaseSeat, void(std::pair<Time, std::string>));
    MOCK_CONST_METHOD0(getNbOfPassengers, int());
    MOCK_METHOD1(increasePassengersNumber, void(int));
	MOCK_METHOD1(takeASeat, void(Passenger));
	MOCK_METHOD0(getFreeSeatsInBus, int());
	MOCK_METHOD0(hasToBackToDepot, bool());
	
};
