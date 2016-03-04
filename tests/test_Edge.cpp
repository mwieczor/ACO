#include <gtest/gtest.h>

#include "Edge.hpp"


class TestEdge: public testing::Test{
public:
    TestEdge(){}
    Edge sut;
};


TEST_F(TestEdge, settingNodes){
   sut.setNodes(Node(Coordinate(32, 42)), Node(Coordinate(12, 15)));

   EXPECT_EQ(sut.startNode(), Node(Coordinate(32, 42)));

}
