#include "PheromonWeightEltist.hpp"


void PheromonWeightEltist::leaveAdditionalPheromon(WeightGraph &g, Edge &e)
{
    g.changeEdgeWeight(e, 5); ///TODO value of pheromon
}
