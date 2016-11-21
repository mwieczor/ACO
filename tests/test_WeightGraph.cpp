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
        WeightGraph wG;
        wG.append(Edge(Node(Coordinate(5,6)), Node(Coordinate(7,8))));
        wG.append(Edge(Node(Coordinate(5,6)), Node(Coordinate(7,9))));
        sut = std::make_unique<WeightGraph>(wG);
    }

    std::unique_ptr<WeightGraph> sut;
	std::vector<BusStop> mBusStop;
    Edge edge1;
    Edge edge2;
};
TEST_F(TestWeightGraph, appendEdges){
    EXPECT_EQ(sut->size(), 2);
    edge2.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,8)));
    EXPECT_EQ(sut->at(0), edge2);
}
TEST_F(TestWeightGraph, isEdgeInGraph){
    edge1.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,8)));
    EXPECT_TRUE(sut->isEdgeInGraph(edge1));
    EXPECT_FALSE(sut->isEdgeInGraph(edge2));
}

TEST_F(TestWeightGraph, searchNeighbours){
    edge1.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,8)));
    edge2.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,9)));
    EXPECT_EQ(edge1, sut->searchNeighbours(Node(Coordinate(5,6))).at(0));
    EXPECT_EQ(edge2,  sut->searchNeighbours(Node(Coordinate(5,6))).at(1));
}


TEST_F(TestWeightGraph, changeEdgeWeight){
    sut->changeEdgeWeight(Node(Coordinate(5,6)), Node(Coordinate(7,8)), 5);
    EXPECT_EQ(sut->at(0).getWeight(), Weight(0.2));
}

TEST_F(TestWeightGraph, searchEdge){
    EXPECT_EQ(sut->edge(Node(Coordinate(5,6)), Node(Coordinate(7,8))), sut->at(0));
}

TEST_F(TestWeightGraph, createGraph){
	sut->createGraph(mBusStop);
    //EXPECT_EQ()
}
