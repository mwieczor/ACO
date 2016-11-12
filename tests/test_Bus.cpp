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
