#pragma once
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
template<typename A>
class SafeQueue
{
  
  std::condition_variable m_variable;

  std::mutex m_mutex;

  std::queue<A> m_queue;

 public:
 
  bool empty();

  A front();

  void push(A fun);

  A pop();

};
#include "SafeQueue.hpp"

