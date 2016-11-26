#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "Scheduler.hpp"
#include "MockBus.cpp"
#include "MockWeightGraph.hpp"
#include "MockEltistAntSystem.hpp"

using ::testing::Return;
using ::testing::Invoke;

class TestScheduler : public testing::Test {
public:
  TestScheduler() {
    mBusMock = std::make_unique<::testing::NiceMock<MockBus>>();
    std::vector<BusStop> temp = {{{5, 6}, "First Stop"},
                                 {{7, 8}, "Second Stop"},
                                 {{7, 9}, "Third Stop"},
                                 {{9, 10}, "Fifth Stop"}};
    pBusStop = std::make_shared<std::vector<BusStop>>(temp);
    mWeighGraphMock = std::make_shared<::testing::NiceMock<MockWeighGraph>>();
    mEltistAntSystemMock =
        std::make_shared<::testing::StrictMock<MockEltistAntSystem>>();
    sut = std::make_shared<Scheduler>(*mBusMock, *pBusStop, mWeighGraphMock, mEltistAntSystemMock);
  }

  void addPassangers() {
    sut->addPassanger(Time(6, 12), 30, "First Stop", "Second Stop");
    sut->addPassanger(Time(6, 14), 30, "Second Stop", "Third Stop");
    sut->addPassanger(Time(6, 15), 30, "Third Stop", "Second Stop");
  }
  void setDemand() {}

  void setExpectation() {
    EXPECT_CALL(*mWeighGraphMock, createGraph(*pBusStop))
        .WillRepeatedly(Return());
    EXPECT_CALL(*mEltistAntSystemMock, getCalculateRoute())
        .WillRepeatedly(Return(std::vector<Coordinate>()));
  }

  std::unique_ptr<::testing::NiceMock<MockBus>> mBusMock;
  std::shared_ptr<std::vector<BusStop>> pBusStop;
  std::shared_ptr<::testing::NiceMock<MockWeighGraph>> mWeighGraphMock;
  std::shared_ptr<::testing::StrictMock<MockEltistAntSystem>>
      mEltistAntSystemMock;
  std::shared_ptr<Scheduler> sut;
};

TEST_F(TestScheduler, addPassagersToSchedule) {
  addPassangers();
  sut->setStartTime(Time(6, 00));
  EXPECT_EQ("Second Stop", sut->getPassanger());
}

TEST_F(TestScheduler, getBusStopForAddedPassangers) {
  ON_CALL(*mWeighGraphMock, createGraph(*pBusStop));
  addPassangers();
  setExpectation();
  sut->setStartTime(Time(6, 00));
  sut->schedule();
  EXPECT_EQ("First Stop", sut->getSchedule());
}

TEST_F(TestScheduler, addPassengersWithWrongBusStop) {
  addPassangers();
  setExpectation();
  sut->setStartTime(Time(7, 13));
  sut->addPassanger(Time(7, 20), 30, "Fourth Stop", "Second Stop");
  sut->schedule();
  EXPECT_EQ("No passengers in this time", sut->getSchedule());
}

TEST_F(TestScheduler, noPassengersInParticularTimeWindow) {
  setExpectation();
  sut->schedule();
  EXPECT_EQ("No passengers in this time", sut->getSchedule());
}

TEST_F(TestScheduler, passengersInParticularTimeWindow) {
  setExpectation();
  addPassangers();
  sut->setStartTime(Time(7, 13));
  sut->addPassanger(Time(7, 20), 30, "Fifth Stop", "Second Stop");
  sut->schedule();
  EXPECT_EQ("Fifth Stop", sut->getSchedule());
}
TEST_F(TestScheduler, proccedGeneratetRoute) {
  setExpectation();
  addPassangers();
  sut->setStartTime(Time(6, 0));
  ON_CALL(*mBusMock, getPosition()).WillByDefault(Return(Coordinate(9, 10)));
  sut->schedule();
}
