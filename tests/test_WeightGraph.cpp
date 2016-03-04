#include <gtest/gtest.h>

#include "WeightGraph.hpp"

class TestWeightGraph: public testing::Test {
public:
    TestWeightGraph(){}
    WeightGraph sut;
    Edge sut2;
    Edge sut3;

};
TEST_F(TestWeightGraph, appendEdges){
    sut2.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,8)));
    sut.append(sut2);
    EXPECT_EQ(sut.edgeCollection().size(), 1);
    sut3.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,8)));
    EXPECT_EQ(sut.edgeCollection().at(0), sut3);
}
TEST_F(TestWeightGraph, isEdgeInGraph){
    sut2.setNodes(Node(Coordinate(7,6)), Node(Coordinate(7,8)));
    sut.append(sut2);
    EXPECT_FALSE(sut.isEdgeInGraph(sut2));
}

TEST_F(TestWeightGraph, increasingNode){
    //sut.increaseNode();

}
