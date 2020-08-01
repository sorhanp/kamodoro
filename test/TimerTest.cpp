#include <boost/test/unit_test.hpp>

#include <chrono>
#include <thread>

struct TimerTestFixture {
  TimerTestFixture(){

  }
};

class Timer{
  private:
  std::chrono::steady_clock::time_point currentTime;
  std::chrono::steady_clock::time_point endTime = {};
    
  public:
  explicit Timer(std::chrono::nanoseconds duration): currentTime(std::chrono::steady_clock::now()){
    endTime = currentTime + duration;
  };

  auto IsOver(){
    currentTime = std::chrono::steady_clock::now();
    return currentTime >= endTime;
  }

  auto Remaining(){
    currentTime = std::chrono::steady_clock::now();
    return endTime - currentTime;
  }
};

BOOST_FIXTURE_TEST_SUITE(TimerTests, TimerTestFixture)
using namespace std::chrono_literals;

  BOOST_AUTO_TEST_CASE(IsOverMsTest){

    auto waitTime = 100ms;
    Timer timer(waitTime);
    
    // Time is not over.
    BOOST_CHECK_EQUAL(timer.IsOver(), false);
    
    // Time is over after sleep.
    std::this_thread::sleep_for(waitTime);
    BOOST_CHECK(timer.IsOver());
  }

  BOOST_AUTO_TEST_CASE(IsOverSecondsTest){
    auto waitTime = 1s;
    Timer timer(waitTime);
    // Time is not over.
    BOOST_CHECK_EQUAL(timer.IsOver(), false);
    
    // Time is over after sleep.
    std::this_thread::sleep_for(waitTime);
    BOOST_CHECK(timer.IsOver());
  }

  BOOST_AUTO_TEST_CASE(RemainingTest){
    // Convert above 1min to nanoseconds for testing
    auto waitTime = std::chrono::duration_cast<std::chrono::nanoseconds>(1min);
    Timer timer(waitTime);
    
    // Remaining time should be less than waitTime
    std::this_thread::sleep_for(1ns);
    BOOST_CHECK_LT(timer.Remaining().count(), waitTime.count());
  }

BOOST_AUTO_TEST_SUITE_END()