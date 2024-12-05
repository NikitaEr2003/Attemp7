
#include <functional>
#include <iostream>
#include "ThreadPool.h"

int SizePool = std::thread::hardware_concurrency() - 2;

ThreadPool obj(SizePool);

void print1() {
  std::cout << "Nikita" << std::endl << std::this_thread::get_id() << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void print2() {
  std::cout << "Roman" << std::endl << std::this_thread::get_id() << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void AddPrint1() {
  for (int i = 0; i < 2; i++) {
    obj.submit(print1);
  }
  obj.m_empty = true;
}

void AddPrint2() {
  for (int i = 0; i < 2; i++) {
    obj.submit(print2);
  }
  obj.m_empty = true;
}

int main() {

  
  std::thread t1(AddPrint1);
  std::thread t2(AddPrint2);

  for (int i = 0; i < obj.CountPool; i++) {
    obj.m_vector.push_back(std::thread(&ThreadPool::work, std::ref(obj)));
  }

  t1.join();
  t2.join();
}
