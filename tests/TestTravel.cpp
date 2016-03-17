#include <gtest/gtest.h>

#include <Travel.hpp>


class testTravel: public testing::Test{
public:
    Travel sut= Travel(Node(Coordinate(5,6)));
    WeightGraph graph;
    Ant ant;

};


TEST_F(testTravel, generateRoute){ //uzupelnic graf do testow
    sut.setFinalCity(Node(Coordinate(7,8)));
    sut.generateTravel();
    EXPECT_EQ(sut.getRouteLenght(), 20);
}
