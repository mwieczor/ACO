#pragma once
#include<string>
#include <vector>


class DataReader{
public:
    DataReader(){}
    ~DataReader(){}
    std::vector<double>& readDataForGraph();
    void readPassangersData();
    std::vector<std::string> readStopBusData();

private:
    std::vector<double> mData;
    std::vector<std::string> mPassengerData;
    std::vector<std::string> mBusStopData;


};

