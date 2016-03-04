#pragma once

class Coordinate
{
public:
    Coordinate():
        mX(), mY(){}
    Coordinate(double x, double y):
        mX(x), mY(y){}

    double x() const;
    void setX(double x);

    double y() const;
    void setY(double y);

    bool operator==(const Coordinate &other) const {
        return other.mX==this->mX && other.mY==this->mY;
    }


private:
    double mX;
    double mY;

};
