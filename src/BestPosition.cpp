#include "ProbabilityOfChoosingPath.hpp"


boost::optional<Edge> BestPosition::calc()
{

        this->fillNodeProbability();
        if(nodeProbability.size()!=0){
            this->calculateProbability();
            if(chooseBestPosition(neighbour)!=boost::none) ///it makes no sense,do it better
                return chooseBestPosition(neighbour);
            else return boost::none;
        }
        return boost::none;
}

double BestPosition::probabilityNodeChosen(const Edge &E) ///TODO wrong name not verb
{
    mNodeProbability=0;
    mNodeProbability=std::pow(E.getWeight(), 0.5) * std::pow(std::pow(E.getMlenght(),-1),0.5);
    mProbability=mProbability+mNodeProbability;
    return mNodeProbability;

}

void BestPosition::calculateProbability()
{
    for (int i=0; i<nodeProbability.size(); i++){
        nodeProbability.at(i)=nodeProbability.at(i)/mProbability;
    }
}

int BestPosition::bestProbabilityPosition() const ///TODO refactor
{

    double max=0;
    int bestPosition=0;
    std::random_device rd;
        std::mt19937 gen(rd());
    std::uniform_real_distribution<double> randomGenerator(0,1); /// TODO  doesn't work when random is bigger than possibility
    double random = randomGenerator(gen);
    for (int i=0; i<nodeProbability.size(); i++){
        if(max<nodeProbability.at(i)) // what if there are two the same node's probability?
            bestPosition=i;
        max=nodeProbability.at(i);
    }
    if(max>=random){
       return bestPosition;  //ant moves randomly
    }
    else return -1; //do it diffrent
}

void BestPosition::fillNodeProbability()
{
    mProbability=0;
    nodeProbability.clear();
    for(auto e:neighbour)
       nodeProbability.push_back(this->probabilityNodeChosen(e));
}

boost::optional<Edge> BestPosition::chooseBestPosition(const std::vector<std::reference_wrapper<Edge>> &neighbours) const
{
    if(bestProbabilityPosition()!=-1)
    {
        int i= bestProbabilityPosition();
        return neighbours.at(i).get();
    }
        else return boost::none;
}
