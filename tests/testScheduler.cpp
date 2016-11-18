#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "Scheduler.hpp"
#include "MockBus.cpp"

using ::testing::Return;

class TestScheduler: public testing::Test{
public:
	TestScheduler(){
        mBusMock = std::make_unique<::testing::NiceMock<MockBus>>();
        const std::vector<BusStop>& pBusStop = {{{5,6}, "FirstStop"}, {{7,8}, "Second Stop"}, {{7,9}, "Third Stop"}};
        sut = std::make_shared<Scheduler>(*mBusMock, pBusStop);
	}


    void addPassangers(){
        sut->addPassanger(Time(6,12), 30, "First stop", "Second Stop");
        sut->addPassanger(Time(6,14), 30, "Second stop", "Third Stop");
        sut->addPassanger(Time(6,15), 30, "First stop", "Second Stop");
    }

    std::unique_ptr<::testing::NiceMock<MockBus>> mBusMock;
	std::shared_ptr<Scheduler> sut;

};

TEST_F(TestScheduler, addPassagersToSchedule){
    addPassangers();
    EXPECT_EQ("Second Stop", sut->getPassanger());
}

TEST_F(TestScheduler, getBusStopForAddedPassangers){
    addPassangers();
    sut->schedule();
    EXPECT_EQ("First Stop", sut->getSchedule());
}

TEST_F(TestScheduler, findLastStopInTimeWindow)
{
//    sut->schedule(Time(3,12), "First Stop");
//    sut->schedule(Time(3,11), "Second Stop");
//    sut->schedule(Time(3,41), "Third Stop");
    EXPECT_EQ("Second Stop", sut->getSchedule());
}



TEST_F(TestScheduler, addTwoPassagersAtTheSameTimeToSchedule){
	sut->addPassanger(Time(3,12), 30, "First stop", "Second Stop");
	sut->addPassanger(Time(3,12), 15, "First stop", "Third Stop");
	EXPECT_EQ("Third Stop", sut->getPassanger());

}

TEST_F(TestScheduler, setStartStopAsADepot){
    sut->addPassanger(Time(6,12), 30, "First stop", "Second Stop");
    sut->addPassanger(Time(6,15), 15, "First stop", "Third Stop");
   ON_CALL(*mBusMock, getPosition()).WillByDefault(Return(Coordinate(5,6)));
   sut->schedule();
   //EXPECT_EQ(sut->getPassangers(), "Second Stop");
}
