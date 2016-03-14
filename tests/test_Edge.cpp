#include <gtest/gtest.h>

#include "Edge.hpp"


class TestEdge: public testing::Test{
public:
    TestEdge(){}
    Edge sut;
    Edge sut2;

};


TEST_F(TestEdge, settingNodes){
    sut.setNodes(Node(Coordinate(32, 42)), Node(Coordinate(12, 15)));
    EXPECT_EQ(sut.startNode(), Node(Coordinate(32, 42)));

}

TEST_F(TestEdge, eqEdges){
    sut.setNodes(Node(Coordinate(32, 42)), Node(Coordinate(12, 15)));
    sut2.setNodes(Node(Coordinate(32, 42)), Node(Coordinate(12, 15)) );
    EXPECT_EQ(sut,sut2);
}

TEST_F(TestEdge, checkingEdges){
    EXPECT_TRUE(sut.chceckEdges(sut2));
}


TEST_F(TestEdge, getOtherNode){
    sut.setNodes(Node(Coordinate(32, 42)), Node(Coordinate(12, 15)));
    EXPECT_EQ(sut.getOtherNode(Node(Coordinate(32, 42))), Node(Coordinate(12, 15)));
}

TEST_F(TestEdge, checkEdgeByNodes){
    sut.setNodes(Node(Coordinate(32, 42)), Node(Coordinate(12, 15)));
    EXPECT_TRUE(sut.hasNode(Node(Coordinate(32, 42))));
    EXPECT_TRUE(sut.hasNode(Node(Coordinate(12, 15))));
}

TEST_F(TestEdge, changeWeight){
    sut.incrementWeight(5);
    EXPECT_EQ(sut.getWeight(), Weight(5));
}
