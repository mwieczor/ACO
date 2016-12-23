#include <gtest/gtest.h>

#include <EltistAntSystem.hpp>

class testTravel: public testing::Test{
public:
    testTravel(){
     std::vector<double> lVector{};
     graph  = std::make_shared<WeightGraph>(lVector);
     sut= std::make_shared<EltistAntSystem>();
    }

    std::shared_ptr<WeightGraph> graph;
    std::shared_ptr<EltistAntSystem> sut;

    Ant ant;

    Edge edge1;
    Edge edge2;
    Edge edge3;
    Edge edge4;
    void buildTest(){
        edge1= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,8)), 5, Weight((0.80)));
        edge2= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,9)), 3, Weight(0.33));
        edge3= Edge(Node(Coordinate(7,8)), Node(Coordinate(8,10)), 10, Weight(0.1));
        edge4= Edge(Node(Coordinate(7,9)), Node(Coordinate(8,10)), 15, Weight(0.06));
        graph->push_back(edge1);
        graph->push_back(edge2);
        graph->push_back(edge3);
        graph->push_back(edge4);
		setRouteParameters(*graph);
    }
	
	void setRouteParameters(IWeightGraph &graph)
	{
		sut->setFinalCity(Coordinate(8,10));
		sut->setStartCity(Coordinate(5,6));
        sut->setGraph(graph);
	}
};



TEST_F(testTravel, generateRoute){
    buildTest();
    auto l = sut->getCalculateRoute();
    EXPECT_EQ(sut->getRouteLenght(), 15);
}

TEST_F(testTravel, graphWithEqualWeigh)
{
  edge1 =
      Edge(Node(Coordinate(5, 6)), Node(Coordinate(7, 8)), 5, Weight((0.1)));
  edge2 = Edge(Node(Coordinate(5, 6)), Node(Coordinate(7, 9)), 3, Weight(0.1));
  edge3 =
      Edge(Node(Coordinate(7, 8)), Node(Coordinate(8, 10)), 10, Weight(0.1));
  edge4 =
      Edge(Node(Coordinate(7, 9)), Node(Coordinate(8, 10)), 15, Weight(0.1));
  graph->push_back(edge1);
  graph->push_back(edge2);
  graph->push_back(edge3);
  graph->push_back(edge4);
  setRouteParameters(*graph);
  sut->getCalculateRoute();
  EXPECT_EQ(sut->getRouteLenght(), 15);
}

TEST_F(testTravel, graphWithTwoEqualPathLenghtAndDifWeight)
{
  edge1 =
      Edge(Node(Coordinate(5, 6)), Node(Coordinate(7, 8)), 3, Weight((0.1)));
  edge2 = Edge(Node(Coordinate(5, 6)), Node(Coordinate(7, 9)), 3, Weight(0.7));
  edge3 =
      Edge(Node(Coordinate(7, 8)), Node(Coordinate(8, 10)), 10, Weight(0.1));
  edge4 =
      Edge(Node(Coordinate(7, 9)), Node(Coordinate(8, 10)), 15, Weight(0.1));
  graph->push_back(edge1);
  graph->push_back(edge2);
  graph->push_back(edge3);
  graph->push_back(edge4);
  setRouteParameters(*graph);
  sut->getCalculateRoute();
  EXPECT_EQ(sut->getRouteLenght(), 13);
}
