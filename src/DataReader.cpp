#include "DataReader.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "Edge.hpp"


void DataReader::readDataForGraph()
{
        std::ifstream file("/home/bwieczor/data1.csv");
        std::string temp;
        while ( file.good() )
        {
                std::getline ( file, temp, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
                mData.push_back(std::stod(temp));
        }
        parseData();
}

void DataReader::readPassangersData()
{
    std::ifstream file("/home/bwieczor/data1.csv");
    std::string temp;
    while ( file.good() )
    {
            std::getline ( file, temp, ',' );
            mPassengerData.push_back(std::stod(temp));
    }

}

void DataReader::parseData()
{
//        for(int i= 4; i<mData.size(); i+=4)
//              //  append(Edge(Node({mData[i-4], mData[i-3]}), Node({mData[i-2], mData[i-1]}), mData[i], {0.1}));
}
