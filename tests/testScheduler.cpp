#include <gtest/gtest.h>
#include <memory>
#include "Scheduler.hpp"

class TestScheduler: public testing::Test{
public:
	TestScheduler(){
		sut = std::make_shared<Scheduler>();
	}
	std::shared_ptr<Scheduler> sut;
};

TEST_F(TestScheduler, createSchedule){
	sut->schedule(Time(3,12), "First Stop");
	sut->schedule(Time(3,11), "Second Stop");
	EXPECT_EQ("Second Stop", sut->getSchedule());
}
