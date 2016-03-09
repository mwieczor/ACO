#include <gtest/gtest.h>

#include <Ant.hpp>

class TestAnt: public testing::Test{
public:
    Ant sut;

};


TEST_F(TestAnt, changeNode){

    sut.changePosition(Node(Coordinate(32,45)));
    EXPECT_EQ(sut.position(),Node(Coordinate(32, 45)));
}
