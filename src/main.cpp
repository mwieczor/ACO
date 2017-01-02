#include "DataReader.hpp"
#include "WeightGraph.hpp"
#include "Scheduler.hpp"
#include "EltistAntSystem.hpp"
#include <vector>
#include <memory>


int main(){
    DataReader mDataReader;
    std::shared_ptr<IWeightGraph> mWeightGraph = std::make_shared<WeightGraph>(mDataReader.readDataForGraph());
    auto mBusStop = mDataReader.readStopBusData();
    auto mAntColony = std::make_shared<EltistAntSystem>();
    auto mPassangerData = mDataReader.readPassangersData();
    std::shared_ptr<Scheduler> mScheduler = std::make_shared<Scheduler>(*mAntColony, mBusStop, mWeightGraph);
    mScheduler->schedule(mPassangerData);


}
