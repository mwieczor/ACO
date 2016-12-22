#include "DataReader.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "Edge.hpp"


std::vector<double> &DataReader::readDataForGraph()
{
        std::ifstream file("/home/bwieczor/data1.csv");
        std::string temp;
        while ( file.good() )
        {
                std::getline ( file, temp, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
                mData.push_back(std::stod(temp));
        }
        return mData;
}

void DataReader::readPassangersData()
{
    std::ifstream file("/home/bwieczor/data1.csv");
    std::string temp;
    while ( file.good() )
    {
            std::getline ( file, temp, ',' );
            mPassengerData.push_back(temp);
    }

}

