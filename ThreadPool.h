#pragma once
#include "SafeQueue.h"
#include <vector>
#include <functional>
class ThreadPool {
 public:

	SafeQueue<std::function<void()>> m_queue;

	ThreadPool(int size);

	ThreadPool() = delete;

	~ThreadPool();

	int CountPool;

	std::vector <std::thread> m_vector;

	void work();

	bool m_empty = false;

    void submit(const std::function<void()> func);
           
};

