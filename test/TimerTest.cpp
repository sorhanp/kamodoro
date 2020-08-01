#include <boost/test/unit_test.hpp>

#include <chrono>
#include <thread>

struct TimerTestFixture {
  TimerTestFixture(){

  }
};

class Timer{
    public:
    explicit Timer(std::chrono::nanoseconds duration): currentTime(std::chrono::steady_clock::now()){
      endTime = currentTime + duration;
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
using namespace std::chrono_literals;

  BOOST_AUTO_TEST_CASE(isOverMsTest){

    auto waitTime = 100ms;
    Timer timer(waitTime);
    
    // Time is not over.
    BOOST_CHECK_EQUAL(timer.isOver(), false);
    
    // Time is over after sleep.
    std::this_thread::sleep_for(waitTime);
    BOOST_CHECK(timer.isOver());
  }

  BOOST_AUTO_TEST_CASE(isOverSecondsTest){
    auto waitTime = 1s;
    Timer timer(waitTime);
    // Time is not over.
    BOOST_CHECK_EQUAL(timer.isOver(), false);
    
    // Time is over after sleep.
    std::this_thread::sleep_for(waitTime);
    BOOST_CHECK(timer.isOver());
  }

BOOST_AUTO_TEST_SUITE_END()