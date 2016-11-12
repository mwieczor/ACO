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
	sut->schedule();
}
