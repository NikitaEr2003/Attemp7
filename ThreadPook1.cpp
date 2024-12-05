#include "ThreadPool.h"

void ThreadPool::submit(const std::function<void()> func) {
  
  m_queue.push(func);
}

void ThreadPool::work() {
  while (!m_empty) {
    std::function<void()> task;

    if (!m_queue.empty()) {
      task = m_queue.front();
      task();
      m_queue.pop();

    } else {
      std::this_thread::yield();
    }

  }
}

ThreadPool::ThreadPool(int size): CountPool(size) {}

ThreadPool::~ThreadPool(){
  for (int i = 0; i < CountPool; i++) {
    if (m_vector[i].joinable())
    m_vector[i].join();
  }
}
