#include <gtest/gtest.h>

#include <Node.hpp>

class TestNodes: public testing::Test {
public:
    Node sut;
};


TEST_F(TestNodes, eqNodes){
    sut=Node(Coordinate(5,6));
    EXPECT_EQ(sut, Node(Coordinate(5,6)));

}
