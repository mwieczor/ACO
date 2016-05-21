#include "BestPosition.hpp"


Edge BestPosition::calc() // always return Edge, ant must move
{
    this->fillNodeProbability();
    //if(nodeProbability.size()!=0){
    this->calculateProbability();
    return chooseBestPosition();

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
    for (auto p:nodeProbability){
        p.second=p.second/mProbability;
    }
}

int BestPosition::bestProbabilityPosition()  ///TODO refactor
{
    double highestProbability=0;
    std::pair<int, double> bestPosition;
    if(nodeProbability.size()>1)
    {
        for (auto p:nodeProbability)
        {
            if(highestProbability<p.second)
            {
                highestProbability=p.second;
                bestPosition=p;
            }
        }
        generateRandom();
        if(isProbabilityEnoughtToMove(highestProbability)){
            return bestPosition.first;  //ant moves randomly
        }
        else
        {
            nodeProbability.remove(bestPosition);
            return bestProbabilityPosition();
        }
    }
    else return bestPosition.first;


}

void BestPosition::fillNodeProbability()
{
    mProbability=0;
    for(int i=0; i<neighbour.size(); i++)
        nodeProbability.push_back(std::make_pair(i, this->probabilityNodeChosen(neighbour[i])));
}

bool BestPosition::isProbabilityEnoughtToMove(double probability) const
{
    return (random<=probability);
}

void BestPosition::generateRandom()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0); /// TODO  doesn't work when random is bigger than possibility
    random = dist(gen);

}


Edge BestPosition::chooseBestPosition()
{
    return neighbour.at(bestProbabilityPosition()).get();

}
