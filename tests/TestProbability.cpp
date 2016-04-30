#include <gtest/gtest.h>

#include "BestPosition.hpp"

class TestProbability: public testing::Test{
public:
    TestProbability(){}
    BestPosition sut;
};


TEST_F(TestProbability, calcProbability){

  //  EXPECT_EQ(1, sut.calc());
}
