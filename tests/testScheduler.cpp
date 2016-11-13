#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "Scheduler.hpp"
#include "MockBus.cpp"

class TestScheduler: public testing::Test{
public:
	TestScheduler(){
		sut = std::make_shared<Scheduler>();
		mBusMock = std::make_unique<::testing::NiceMock<MockBus>>();
	}
	std::shared_ptr<Scheduler> sut;
	std::unique_ptr<::testing::NiceMock<MockBus>> mBusMock;
};

TEST_F(TestScheduler, sortDataInSchedule){
	sut->schedule(Time(3,12), "First Stop");
	sut->schedule(Time(3,11), "Second Stop");
	EXPECT_EQ("Second Stop", sut->getSchedule());
}

TEST_F(TestScheduler, addPassagersToSchedule){
	sut->addPassanger(Time(3,12), 30, "First stop", "Second Stop");
	sut->addPassanger(Time(3,14), 30, "First stop", "Third Stop");
	sut->addPassanger(Time(3,15), 30, "First stop", "Fourth Stop");

	EXPECT_EQ("Second Stop", sut->getPassanger());
}
