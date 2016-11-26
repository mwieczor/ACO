#include <gtest/gtest.h>

#include "Coordinate.hpp"


class TestCoordinate: public testing::Test{
public:
    Coordinate sut;
};


TEST_F(TestCoordinate, push_backCoordinate){
    sut.setX(5);
    sut.setY(6);
    EXPECT_EQ(sut.x(), 5); // czy jest sens?
    EXPECT_EQ(sut.y(), 6);
}

TEST_F(TestCoordinate, eqCoordinate){
    sut.setX(5);
    sut.setY(6);
    EXPECT_EQ(sut, Coordinate(5,6));
}
