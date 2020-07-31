#include <boost/test/unit_test.hpp>

#include <chrono>
#include <thread>

struct TimerTestFixture {
  TimerTestFixture(){

  }
};

class Timer{
    public:
    Timer(std::chrono::seconds waitTime){
        currentTime = std::chrono::steady_clock::now();
        endTime = currentTime + std::chrono::seconds(waitTime);
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

  BOOST_AUTO_TEST_CASE(TimerIsOver){
      auto waitTime = std::chrono::seconds(1);
      Timer timer(waitTime);
      
      // Time is not over.
      BOOST_CHECK_EQUAL(timer.isOver(), false);
      
      // Time is over after sleep.
      std::this_thread::sleep_for(std::chrono::seconds(1));
      BOOST_CHECK(timer.isOver());
  }

BOOST_AUTO_TEST_SUITE_END()