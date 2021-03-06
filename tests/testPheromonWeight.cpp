#include <gtest/gtest.h>

#include "PheromonWeight.hpp"
#include "Ant.hpp"


class TestPheromonWeight: public testing::Test{
public:
    TestPheromonWeight(){
        edge1= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,8)), 5, Weight(1));
        edge2= Edge(Node(Coordinate(7,6)), Node(Coordinate(7,8)), 5, Weight(1));
    }

    PheromonWeight sut;
    Ant ant1;
    Edge edge1;
    Edge edge2;
};

//TEST_F(TestPheromonWeight, changeWeight){
//    graph.push_back(edge1);
//    ant1.setPosition(Node(Coordinate(5,6)));
//    ant1.moveAnt(graph.searchNeighbours(Node(Coordinate(5,6))));
//    sut.leavePheromon(graph, ant1.getBestPosition());
//    //EXPECT_EQ(graph[0].getWeight(), 6); //need to work on access to edge
//}

//TEST_F(TestPheromonWeight, vanishPheromon){
//    graph.push_back(edge1);
//    sut.evaporatePheromon(graph);
//    EXPECT_EQ(graph[0].getWeight(), 0.95);
//}
