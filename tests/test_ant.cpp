#include <gtest/gtest.h>

#include <Ant.hpp>

class TestAnt: public testing::Test{
public:
    TestAnt(){
        ///NOTE BW nie rób tego w testach, tylko tutaj, nie duplikuj kodu
        edge1= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,8)), 5, Weight(1));
        edge2= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,9)), 3, Weight(5));
        edge3= Edge(Node(Coordinate(7,8)), Node(Coordinate(8,10)), 15, Weight(1));
        edge4= Edge(Node(Coordinate(7,9)), Node(Coordinate(8,10)), 5, Weight(15));
    }

    std::unique_ptr<Ant> sut = std::make_unique<Ant>(Node(Coordinate(5,6)));
    WeightGraph graph;

    ///NOTE BW może lepiej vector<Edge> ?
    Edge edge1;
    Edge edge2;
    Edge edge3;
    Edge edge4;
    Edge edge5;
};


TEST_F(TestAnt, moveAntOneNode){
    graph.append(edge1);
    sut->moveAnt(graph.searchNeighbours(sut->position()));
    EXPECT_EQ(sut->position(),Node(Coordinate(7,8)));
    sut->moveAnt(graph.searchNeighbours(Node(Coordinate(7,8))));
    EXPECT_EQ(sut->position(),Node(Coordinate(7,8)));
}


TEST_F(TestAnt, moveAntTwoEdges){
    graph.append(edge1);
    graph.append(edge3);
    sut->moveAnt(graph.searchNeighbours(sut->position()));
    EXPECT_EQ(sut->position(),Node(Coordinate(7,8)));
    sut->moveAnt(graph.searchNeighbours(sut->position()));
    EXPECT_EQ(sut->position(),Node(Coordinate(8,10)));
}

TEST_F(TestAnt, moveAntSameEdges){ //czy zakladamy ze taka sytuacji nie wystapi?
    graph.append(edge1);
    edge3.setNodes(Node(Coordinate(5,6)), Node(Coordinate(7,8)));
    graph.append(edge3);
    sut->moveAnt(graph.searchNeighbours(sut->position()));
    EXPECT_EQ(sut->position(),Node(Coordinate(7,8)));
}

TEST_F(TestAnt, moveAnt){
    graph.append(edge1);
    graph.append(edge2);
    graph.append(edge3);
    graph.append(edge4);
    graph.append(edge5);
    ///TODO FIRST! sth wrong with search neighbours!
    sut->moveAnt(graph.searchNeighbours(sut->position()));
   EXPECT_EQ(sut->position(),Node({7,9}));
}

//TEST_F(TestAnt, increaseWeight){ //czy zakladamy ze taka sytuacji nie wystapi?
//    graph.append(edge1);
//    sut->setPosition(Node(Coordinate(5,6)));
//    edge1.setWeight(Weight(1));
//    sut->moveAnt(graph.searchNeighbours(sut->position()));
//    EXPECT_EQ(edge1.getWeight().weight(),6);


//}


