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
        sut = std::make_shared<Scheduler>(*mBusMock);
	}
    std::unique_ptr<::testing::NiceMock<MockBus>> mBusMock;
	std::shared_ptr<Scheduler> sut;

};

TEST_F(TestScheduler, sortDataInSchedule){
	sut->schedule(Time(3,12), "First Stop");
	sut->schedule(Time(3,11), "Second Stop");
	EXPECT_EQ("Second Stop", sut->getSchedule());
}

TEST_F(TestScheduler, addPassagersToSchedule){
	sut->addPassanger(Time(3,12), 30, "First stop", "Second Stop");
    sut->addPassanger(Time(3,14), 30, "Second stop", "Third Stop");
	sut->addPassanger(Time(3,15), 30, "First stop", "Fourth Stop");

	EXPECT_EQ("Second Stop", sut->getPassanger());
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
   sut->prepareDataForGraph();
   //EXPECT_EQ(sut->getPassangers(), "Second Stop");
}
