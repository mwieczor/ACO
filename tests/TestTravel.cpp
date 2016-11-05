#include <gtest/gtest.h>

#include <EltistAntSystem.hpp>

class testTravel: public testing::Test{
public:
    testTravel(){

    }
    std::shared_ptr<EltistAntSystem> sut;
    std::unique_ptr<WeightGraph> graph  = std::make_unique<WeightGraph>();

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
        graph->append(edge1);
        graph->append(edge2);
        graph->append(edge3);
        graph->append(edge4);
        sut = std::make_shared<EltistAntSystem> (Node(Coordinate(5,6)), *graph);
    }
};


TEST_F(testTravel, generateRoute){
    buildTest();
    sut->createAntColony();
    sut->setFinalCity(Node(Coordinate(8,10)));
    sut->generateRoute();
    EXPECT_EQ(sut->getRouteLenght(), 15);
}

TEST_F(testTravel, graphWithEqualWeigh)
{
    edge1= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,8)), 5, Weight((0.1)));
    edge2= Edge(Node(Coordinate(5,6)), Node(Coordinate(7,9)), 3, Weight(0.1));
    edge3= Edge(Node(Coordinate(7,8)), Node(Coordinate(8,10)), 10, Weight(0.1));
    edge4= Edge(Node(Coordinate(7,9)), Node(Coordinate(8,10)), 15, Weight(0.1));
    graph->append(edge1);
    graph->append(edge2);
    graph->append(edge3);
    graph->append(edge4);
    sut = std::make_shared<EltistAntSystem> (Node(Coordinate(5,6)), *graph);

    sut->createAntColony();
    sut->setFinalCity(Node(Coordinate(8,10)));
    sut->generateRoute();
    EXPECT_EQ(sut->getRouteLenght(), 15);
}
//testTravel(){

//}
//std::shared_ptr<EltistAntSystem> sut;
//std::unique_ptr<WeightGraph> graph = std::make_unique<WeightGraph>();
//std::vector<Edge> edges;
//std::array<double, 4> weights;
//std::array<int, 4> lenghts;

//Ant ant;

//void createEdgesWithDefultWeight(auto lenghts)
//{
//    edges.clear();
//    for(int i=0; i<lenghts.size(); i++)
//        edges.push_back(Edge(Node(Coordinate(5,6)), Node(Coordinate(7,8)), lenghts[i], Weight((0.1))));

//}

//void setWeighToEdges(auto weights){
//    for(int i=0; i<weights.size(); i++)
//        edges[i].setWeight(Weight(weights[i]));
//}

//void addEdgesToGraph()
//{
//    for(auto e : edges)
//        graph->append(e);
//}
//void buildTest()
//{
//    sut = std::make_shared<EltistAntSystem> (Node(Coordinate(5,6)), *graph);
//}
//};


//TEST_F(testTravel, generateRoute){
//lenghts = {3,5,15,10};
//weights = {0.8,0.33,0.1,0.06};
//createEdgesWithDefultWeight(lenghts);
//setWeighToEdges(weights);
//addEdgesToGraph();
//buildTest();
//sut->createAntColony();
//sut->setFinalCity(Node(Coordinate(8,10)));
//sut->generateRoute();
//EXPECT_EQ(sut->getRouteLenght(), 15);
//}

//TEST_F(testTravel, graphWithEqualWeighAndLenght){

//}
