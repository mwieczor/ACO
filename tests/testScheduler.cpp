#include "MockBus.hpp"
#include "MockEltistAntSystem.hpp"
#include "MockWeightGraph.hpp"
#include "Scheduler.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>

using ::testing::Return;
using ::testing::Invoke;
namespace testing {



class TestScheduler : public testing::Test {
public:
  TestScheduler() {
    mBusMock = std::make_unique<::testing::NiceMock<MockBus>>();
    std::vector<std::string> temp = {"5", "6", "First Stop",
                                 "7", "8", "Second Stop",
                                 "7", "9", "Third Stop",
                                 "9", "10", "Fifth Stop"};

    mWeighGraphMock = std::make_shared<::testing::NiceMock<MockWeighGraph>>();
    mEltistAntSystemMock =
        std::make_shared<::testing::StrictMock<MockEltistAntSystem>>();
    sut = std::make_shared<Scheduler>( *mEltistAntSystemMock, temp, mWeighGraphMock);
  }

  void addPassangers() {
    sut->addPassanger(Time(6, 12), "First Stop", "Second Stop");
    sut->addPassanger(Time(6, 14), "Second Stop", "Third Stop");
    sut->addPassanger(Time(6, 15), "Third Stop", "Second Stop");
  }
  void setDemand() {}

  void setExpectation() {
    createRawSchedule();
    EXPECT_CALL(*mWeighGraphMock, createGraph(_))
        .WillRepeatedly(Return());
    EXPECT_CALL(*mEltistAntSystemMock, getCalculateRoute())
        .WillRepeatedly(Return(mRawSchedule));
	EXPECT_CALL(*mEltistAntSystemMock, setFinalCity(_))
        .WillRepeatedly(Return());
	EXPECT_CALL(*mEltistAntSystemMock, setStartCity(_))
        .WillRepeatedly(Return());
	EXPECT_CALL(*mEltistAntSystemMock, setGraph(_))
        .WillRepeatedly(Return());
  }
  void createRawSchedule() {
    mRawSchedule.push_back({{9, 10}, 0});
    mRawSchedule.push_back({{7, 8}, 5});
    mRawSchedule.push_back({{7, 9}, 2});
    mRawSchedule.push_back({{5, 6}, 2});
  }

  std::unique_ptr<::testing::NiceMock<MockBus>> mBusMock;
  std::shared_ptr<std::vector<BusStop>> pBusStop;
  std::shared_ptr<::testing::NiceMock<MockWeighGraph>> mWeighGraphMock;
  std::shared_ptr<::testing::StrictMock<MockEltistAntSystem>>
      mEltistAntSystemMock;
  std::vector<std::pair<Coordinate, int>> mRawSchedule;
  std::shared_ptr<Scheduler> sut;
};

TEST_F(TestScheduler, addPassagersToSchedule) {
  addPassangers();
  sut->setStartTime(Time(6, 00));
  EXPECT_EQ("Second Stop", sut->getPassanger());
}

TEST_F(TestScheduler, getBusStopForAddedPassangers) {
  ON_CALL(*mWeighGraphMock, createGraph(_));
  addPassangers();
  setExpectation();
  sut->setStartTime(Time(6, 15));
  sut->schedule();
  auto first = sut->getSchedule().begin();
  first++;
  EXPECT_EQ("Third Stop", first->second);
}

TEST_F(TestScheduler, addPassengersWithWrongBusStop) {
  setExpectation();
  sut->setStartTime(Time(7, 13));
  sut->addPassanger(Time(7, 20), "Fourth Stop", "Second Stop");
  sut->schedule();
  auto first = sut->getSchedule().begin();
  
  EXPECT_EQ("No passengers in this time", first->second);
}

TEST_F(TestScheduler, passengersInParticularTimeWindow) {
  setExpectation();
  addPassangers();
  sut->setStartTime(Time(7, 13));
  sut->addPassanger(Time(7, 20), "Fifth Stop", "Second Stop");
  sut->schedule();
  auto first = sut->getSchedule().begin();
  
  EXPECT_EQ("Fifth Stop", first->second);
}
TEST_F(TestScheduler, proccedGeneratedRoute) {
  setExpectation();
  addPassangers();
  sut->setStartTime(Time(6, 0));
  ON_CALL(*mBusMock, getPosition()).WillByDefault(Return(Coordinate(9, 10)));
  createRawSchedule();
  sut->schedule();
 // EXPECT_EQ("Fifth Stop", sut->getSchedule());
}

TEST_F(TestScheduler, notAllPassangersTaken) {
  setExpectation();
  sut->setStartTime(Time(6, 0));
  ON_CALL(*mBusMock, getPosition()).WillByDefault(Return(Coordinate(9, 10)));
  ON_CALL(*mBusMock, getFreeSeatsInBus()).WillByDefault(Return(5));
  createRawSchedule();
  sut->schedule();
  //EXPECT_EQ("One of passanger is not taken from stop", sut->getSchedule());
}
}
