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
	EXPECT_EQ(5, sut->getCapacity());
}
TEST_F(testBus, releaseSeat){
	sut->releaseSeat(3);
	EXPECT_EQ(2, sut->getCapacity());
}

TEST_F(testBus, increaseNbOfPassangers){
	sut->releaseSeat(3);
	sut->increasePassangersNumber(3);
	EXPECT_EQ(5, sut->getCapacity());
}


