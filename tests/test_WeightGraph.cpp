#include <gtest/gtest.h>

#include "WeightGraph.hpp"
#include "Edge.hpp"
#include "Bus.hpp"
#include <memory>


class TestWeightGraph: public testing::Test {
public:
    TestWeightGraph()
    {
        mBusStop =  {{{5, 6}, "First Stop"},
                     {{7, 8}, "Second Stop"},
                     {{7, 9}, "Third Stop"},
                     {{9, 10}, "Fifth Stop"}};
        addEdges();
    }


    void addEdges(){
        std::vector<double> lVector = {5,6,7,8,1,5,6,7,9,1};
        sut = std::make_unique<WeightGraph>(lVector);
    }

    std::unique_ptr<WeightGraph> sut;
	std::vector<BusStop> mBusStop;
    Edge edge1;
    Edge edge2;
};
TEST_F(TestWeightGraph, push_backEdges){
    EXPECT_EQ(sut->size(), 2);
    Edge edge2 {Node(Coordinate(5,6)), Node(Coordinate(7,8)), 1, 0.1};
    EXPECT_EQ(sut->at(0), edge2);
}

TEST_F(TestWeightGraph, searchNeighbours){
    Edge edge1 {Node(Coordinate(5,6)), Node(Coordinate(7,8)), 1, 0.1};
    Edge edge2 {Node(Coordinate(5,6)), Node(Coordinate(7,9)), 1, 0.1};

    EXPECT_EQ(edge1, sut->searchNeighbours(Node(Coordinate(5,6))).at(0));
    EXPECT_EQ(edge2, sut->searchNeighbours(Node(Coordinate(5,6))).at(1));
}


TEST_F(TestWeightGraph, changeEdgeWeight){
    sut->changeEdgeWeight(Node(Coordinate(5,6)), Node(Coordinate(7,8)), 2);
    EXPECT_EQ(sut->at(0).getWeight(), Weight(0.6));
}

TEST_F(TestWeightGraph, searchEdge){
    EXPECT_EQ(sut->edge(Node(Coordinate(5,6)), Node(Coordinate(7,8))), sut->at(0));
}

TEST_F(TestWeightGraph, createGraph){
    mBusStop[0].isDemand= true;
	sut->createGraph(mBusStop);
    EXPECT_TRUE(sut->at(0).startNode().isDemand);
}

TEST_F(TestWeightGraph, parseData){

}
