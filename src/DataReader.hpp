#pragma once
#include<string>
#include <vector>


class DataReader{
public:
    DataReader(){}
    ~DataReader(){}
    std::vector<double>& readDataForGraph();
    void readPassangersData();

private:
    void parseData();
    std::vector<double> mData;
    std::vector<std::string> mPassengerData;

};

