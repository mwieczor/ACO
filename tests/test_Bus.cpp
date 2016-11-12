#include <gtest/gtest.h>
#include <memory>

#include "Bus.hpp"

class testBus: public testing::Test 
{
public:
	testBus(){
		
		sut = std::make_unique<Bus>(Coordinate(5,6), 5);
	}
	
	std::unique_ptr<Bus> sut;
};


TEST_F(testBus, checkBusPosition){
	EXPECT_EQ(Coordinate(5,6), sut->getPosition());
}

TEST_F(testBus, checkBusCapacity)
{
	EXPECT_EQ(0, sut->getNbOfPassangers());
}

TEST_F(testBus, increaseNbOfPassangersWhenAreFreeSeats){
	sut->increasePassangersNumber(3);
	EXPECT_EQ(3, sut->getNbOfPassangers());
}
TEST_F(testBus, releaseSeat){
	sut->increasePassangersNumber(3);
	sut->releaseSeat(1);
	EXPECT_EQ(2, sut->getNbOfPassangers());
}
TEST_F(testBus,increaseNbOfPassangersWhenAreNoFreeSeats){
	sut->increasePassangersNumber(5);
	sut->increasePassangersNumber(3);
	EXPECT_EQ(5, sut->getNbOfPassangers());
}
TEST_F(testBus, increaseNbOfPassangersWhenAreSingleFreeSeats){
	sut->increasePassangersNumber(4);
	sut->increasePassangersNumber(3);
	EXPECT_EQ(5, sut->getNbOfPassangers());
}
