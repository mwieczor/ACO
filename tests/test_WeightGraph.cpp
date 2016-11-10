#include <gtest/gtest.h>

#include "WeightGraph.hpp"
#include "Edge.hpp"
#include <memory>


class TestWeightGraph: public testing::Test {
public:
    TestWeightGraph(){}
    std::unique_ptr<IWeightGraph> sut = std::make_unique<WeightGraph>();
    Edge edge1;
    Edge edge2;
};
TEST_F(TestWeightGraph, appendEdges){
    edge1.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,8)));
    sut->append(edge1);
    EXPECT_EQ(sut->size(), 1);
    edge2.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,8)));
    EXPECT_EQ(sut->at(0), edge2);
}
TEST_F(TestWeightGraph, isEdgeInGraph){
    edge1.setNodes(Node(Coordinate(7,6)), Node(Coordinate(7,8)));
    sut->append(edge1);
    EXPECT_TRUE(sut->isEdgeInGraph(edge1));
    EXPECT_FALSE(sut->isEdgeInGraph(edge2));
}

TEST_F(TestWeightGraph, searchNeighbours){
    edge1.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,8)));
    edge2.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,9)));
    sut->append(edge1);
    sut->append(edge2);
   ;
    EXPECT_EQ(edge1, sut->searchNeighbours(Node(Coordinate(5,6))).at(0));
    EXPECT_EQ(edge2,  sut->searchNeighbours(Node(Coordinate(5,6))).at(1));
}

TEST_F(TestWeightGraph, countNode){
    //sut->increaseNode();
}

TEST_F(TestWeightGraph, changeEdgeWeight){
    //sut->changeEdgeWeight(edge1, 5);
    //EXPECT_EQ(edge1.getWeight(), Weight(5));
}

TEST_F(TestWeightGraph, searchEdge){
    edge1.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,8)));
    sut->append(edge1);
    edge2.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,8)));
   // EXPECT_EQ(sut->edge(edge2), sut->at(0));
}
