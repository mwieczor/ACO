#include <gtest/gtest.h>
#include <memory>

#include "Bus.hpp"

class testBus: public testing::Test 
{
public:
	testBus(){
		
		sut = std::make_unique<Bus>(Coordinate(5,6));
	}
	
	std::unique_ptr<Bus> sut;
};


TEST_F(testBus, checkBusPosition){
	EXPECT_EQ(Coordinate(5,6), sut->getPosition());
}

TEST_F(testBus, checkBusCapacity)
{
    EXPECT_EQ(0, sut->getNbOfPassengers());
}

TEST_F(testBus, increaseNbOfPassangersWhenAreFreeSeats){
    sut->increasePassengersNumber(3);
    EXPECT_EQ(3, sut->getNbOfPassengers());
}
TEST_F(testBus, releaseSeat) //test do poprawy
{
    sut->increasePassengersNumber(3);
	//sut->releaseSeat(1); /
    EXPECT_EQ(2, sut->getNbOfPassengers());
}
TEST_F(testBus,increaseNbOfPassangersWhenAreNoFreeSeats){
    sut->increasePassengersNumber(5);
    sut->increasePassengersNumber(53);
    EXPECT_EQ(50, sut->getNbOfPassengers());
}
TEST_F(testBus, increaseNbOfPassangersWhenIsSingleFreeSeat){
    sut->increasePassengersNumber(49);
    sut->increasePassengersNumber(3);
    EXPECT_EQ(50, sut->getNbOfPassengers());
}

TEST_F(testBus, changeBusPosition){
	sut->ride(Coordinate(7,8), Time(0,3));
	EXPECT_EQ(sut->getPosition(), Coordinate(7,8));
}
