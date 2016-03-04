#include <gtest/gtest.h>

#include "Coordinate.hpp"


class TestCoordinate: public testing::Test{
public:
    Coordinate sut= Coordinate(5,6);
    //sut.setX(5); dlaczego?
    //sut.setY(6);
};


TEST_F(TestCoordinate, appendCoordinate){

    EXPECT_EQ(sut.x(), 5 ); // czy jest sens?
    EXPECT_EQ(sut.y(), 6);
}

TEST_F(TestCoordinate, eqCoordinate){
    EXPECT_EQ(sut, Coordinate(5,6));
}
