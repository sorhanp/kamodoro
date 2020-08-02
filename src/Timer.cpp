#include "Timer.hpp"

Timer::Timer(std::chrono::nanoseconds duration): currentTime(std::chrono::steady_clock::now()){
  endTime = currentTime + duration;
}

bool Timer::IsOver(){
  currentTime = std::chrono::steady_clock::now();
  return currentTime >= endTime;
}

std::chrono::nanoseconds Timer::Remaining(){
  currentTime = std::chrono::steady_clock::now();
  return endTime - currentTime;
}
