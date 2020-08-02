#ifndef TIMER_H
#define TIMER_H
#include <chrono>

class Timer{
  private:
  std::chrono::steady_clock::time_point currentTime;
  std::chrono::steady_clock::time_point endTime = {};
    
  public:
  explicit Timer(std::chrono::nanoseconds duration);

  bool IsOver();
  std::chrono::nanoseconds Remaining();
};

#endif /* TIMER_H */
