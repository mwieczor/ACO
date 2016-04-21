#include <gtest/gtest.h>

#include <Travel.hpp>


class testTravel: public testing::Test{
public:
    testTravel(){
        edge1= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,8)), 5, Weight(1));
        edge2= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,9)), 3, Weight(1));
        edge3= Edge(Node(Coordinate(7,8)), Node(Coordinate(8,10)), 15, Weight(1));
        edge4= Edge(Node(Coordinate(7,9)), Node(Coordinate(8,10)), 5, Weight(1));
        graph.append(edge1);
        graph.append(edge2);
        graph.append(edge3);
        graph.append(edge4);
    }
    Travel sut;
    WeightGraph graph;
    Ant ant;

    Edge edge1;
    Edge edge2;
    Edge edge3;
    Edge edge4;

};


TEST_F(testTravel, generateRoute){ //uzupelnic graf do testow
    sut= Travel(Node(Coordinate(5,6)), graph);
    sut.setFinalCity(Node(Coordinate(8,10)));
    sut.generateTravel();
    EXPECT_EQ(sut.getRouteLenght(), 8);
}
