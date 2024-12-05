#include "SafeQueue.h"
template <typename A>
void SafeQueue<A>::push(A fun) {
  std::lock_guard<std::mutex> lock_m(m_mutex);
  m_queue.push(fun);
  m_variable.notify_one();
}

template <typename A>
A SafeQueue<A>::pop() {
  std::unique_lock<std::mutex> lock_m(m_mutex);

  m_variable.wait(lock_m, [this] { return !empty(); });
  auto first = m_queue.front();
  m_queue.pop();
  return first;
}

template <typename A>
A SafeQueue<A>::front() {
std::unique_lock<std::mutex> lock_m(m_mutex);

  auto f_front = m_queue.front();
  return f_front;
}

template <typename A>
bool SafeQueue<A>::empty() {
  return m_queue.empty();
}
