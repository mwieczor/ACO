#include "Ant.hpp"

void Ant::changePosition(const Node &mN)
{
    this->setPosition(mN);
}

Node Ant::position() const
{
    return mPosition;
}

void Ant::setPosition(const Node &position)
{
    mPosition = position;
}
