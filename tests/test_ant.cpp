#include <gtest/gtest.h>

#include <Ant.hpp>

class TestAnt: public testing::Test{
public:
    TestAnt(){
        ///NOTE BW nie rób tego w testach, tylko tutaj, nie duplikuj kodu
            edge1= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,8)), 5, Weight(1));
            edge2= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,9)), 3, Weight(5));
            edge3= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,10)), 15, Weight(0));
            edge4= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,12)), 5, Weight(15));
    }

    Ant sut;
    WeightGraph graph;

    ///NOTE BW może lepiej vector<Edge> ?
    Edge edge1;
    Edge edge2;
    Edge edge3;
    Edge edge4;
    Edge edge5;
};


TEST_F(TestAnt, changeNode){
    sut.changePosition(Node(Coordinate(32,45)));
    EXPECT_EQ(sut.position(),Node(Coordinate(32, 45)));
}

TEST_F(TestAnt, choosePath){
    ///NOTE BW nie dokładaj sobie pracy, po to masz konstruktur żeby z niego korzystać
    /// poniżej przykład, zrób to samo dla innych testów
//    edge1= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,8)), 5, Weight(1));
//    edge2= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,9)), 3, Weight(5));
//    edge3= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,10)), 15, Weight(0));
//    graph.append(edge1);
//    graph.append(edge2);
//    graph.append(edge3);
//    graph.searchNeighbours(Node(Coordinate(5,6)));
//    EXPECT_EQ(sut.choosePath(graph.neighbours()).endNode(),Node(Coordinate(7,9)));
//    edge4= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,12)), 5, Weight(15));
//    graph.append(edge4);
//    graph.searchNeighbours(Node(Coordinate(5,6)));
//    EXPECT_EQ(sut.choosePath(graph.neighbours()).endNode(),Node(Coordinate(7,12)));

    graph.append(edge1);
    graph.append(edge2);
    graph.append(edge3);
    ///NOTE BW dlaczego nie wyołujesz searchNeighbours(Node(Coordinate(5,6))) bezpośrednio w teście?
//    graph.searchNeighbours(Node(Coordinate(5,6)));
//    EXPECT_EQ(sut.choosePath(graph.neighbours()).endNode(),Node(Coordinate(7,9)));
    EXPECT_EQ(sut.choosePath(graph.searchNeighbours(Node(Coordinate(5,6)))).endNode()
              ,Node(Coordinate(7,9)));

    graph.append(edge4);
    graph.searchNeighbours(Node(Coordinate(5,6)));
    EXPECT_EQ(sut.choosePath(graph.neighbours()).endNode(),Node(Coordinate(7,12)));
}


TEST_F(TestAnt, moveAntOneEdge){
    edge1= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,8)), 5, Weight(1));
    graph.append(edge1);
    sut.setPosition(Node(Coordinate(5,6)));
    sut.moveAnt(graph.searchNeighbours(sut.position()));
    EXPECT_EQ(sut.position(),Node(Coordinate(7,8)));
}

TEST_F(TestAnt, moveAnt){
    edge1= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,8)), 5, Weight(1));
    edge2= Edge(Node(Coordinate(7,8)), Node(Coordinate(8,9)), 3, Weight(1));
    edge3= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,10)), 5, Weight(4));
    edge5= Edge(Node(Coordinate(7,8)), Node(Coordinate(5,6)), 5, Weight(1));
    edge4= Edge(Node(Coordinate(7,10)), Node(Coordinate(8,9)), 5, Weight(1));
    graph.append(edge1);
    graph.append(edge2);
    graph.append(edge3);
    graph.append(edge4);
    graph.append(edge5);
//    sut.setPosition(Node(Coordinate(5,6)));
//    sut.changePosition(sut.choosePath(graph.searchNeighbours(sut.position())));
//    graph.searchNeighbours(sut.position());
//    sut.changePosition(sut.choosePath(graph.neighbours()));
    EXPECT_EQ(sut.position(),Node(Coordinate(8,9)));

}
