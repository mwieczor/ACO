#include "WeightGraph.hpp"

void WeightGraph::append(const Edge &mE)
{
    if(!this->isEdgeInGraph(mE))
        mEdgeCollection.push_back(mE);
    else ; //do nothing
}

bool WeightGraph::isEdgeInGraph(const Edge &mE) const
{
    for(auto edge:mEdgeCollection){
        if(edge.chceckEdges(mE)){
            return true;
        }
    }
    return false;
}

void WeightGraph::changeEdgeWeight(Edge &mE,int mW)
{
    mE.changeWeight(mW);
}

Edge WeightGraph::edge(const Edge &mE) const
{
    for(auto edge:mEdgeCollection){
        if(edge.chceckEdges(mE)){
            return edge;
        }
    }
}

std::vector<Edge> WeightGraph::searchNeighbours(const Node &mN)
{
    ///NOTE BW funkcje szukające zmiennych nie powinny modyfikować obiektu na którym wykonują operację.
    /// Wyjątkiem są niektóre kontenery z CPP które jeżeli nie mają danego klucza,
    /// tworzą go i oddają iterator do nowego wpisu np.
    /// http://en.cppreference.com/w/cpp/container/map/find

    mNeighbours.clear();
    for(auto edge:mEdgeCollection){
        if(edge.hasNode(mN)){
            mNeighbours.push_back(edge);
        }
    }
    return neighbours(); //warunek o braku sasiadow?
}

std::vector<Edge> WeightGraph::edgeCollection() const // nazwa: getGraph?
{
    return mEdgeCollection;
}

std::vector<Edge> WeightGraph::neighbours() const
{
    ///NOTE BW zmienna ta jest zmieniana przez WeightGraph::searchNeighbours()
    /// tworzy to swojego rodzaju problem, bo żeby dostać sąsiadów, najpierw musisz ich wyszukać
    /// czyli tak naprawdę nie użyjesz tej funkcji bezpośrednio nigdy
    /// (ze względu na to że i tak wcześniej musisz wywołać WeightGraph::searchNeighbours, które ci tą wartość zwraca)
    return mNeighbours;
}

