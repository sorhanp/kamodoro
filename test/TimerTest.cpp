#include <boost/test/unit_test.hpp>

#include <chrono>
#include <thread>

struct TimerTestFixture {
  TimerTestFixture(){

  }
};

template <typename TimeFormat> 
class Timer{
    public:
    Timer(auto anyWaitTime): currentTime(std::chrono::steady_clock::now()){
      endTime = currentTime + TimeFormat(anyWaitTime);
    };

    bool isOver(){
        currentTime = std::chrono::steady_clock::now();
        return currentTime > endTime;
    }

    private:
    std::chrono::steady_clock::time_point currentTime;
    std::chrono::steady_clock::time_point endTime;
};

BOOST_FIXTURE_TEST_SUITE(TimerTests, TimerTestFixture)

  BOOST_AUTO_TEST_CASE(isOverMsTest){
    auto waitTime = 10;
    Timer<std::chrono::milliseconds> timer(waitTime);
    
    // Time is not over.
    BOOST_CHECK_EQUAL(timer.isOver(), false);
    
    // Time is over after sleep.
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    BOOST_CHECK(timer.isOver());
  }

  BOOST_AUTO_TEST_CASE(isOverSecondsTest){
    auto waitTime = 1;
    Timer<std::chrono::seconds> timer(waitTime);
    // Time is not over.
    BOOST_CHECK_EQUAL(timer.isOver(), false);
    
    // Time is over after sleep.
    std::this_thread::sleep_for(std::chrono::seconds(waitTime));
    BOOST_CHECK(timer.isOver());
  }

BOOST_AUTO_TEST_SUITE_END()