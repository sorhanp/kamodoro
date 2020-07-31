#include <boost/test/unit_test.hpp>

struct TimerTestFixture {
  TimerTestFixture(){

  }
};

BOOST_FIXTURE_TEST_SUITE(TimerTests, TimerTestFixture)

  BOOST_AUTO_TEST_CASE(TBD){
      BOOST_TEST(true);
  }

BOOST_AUTO_TEST_SUITE_END()