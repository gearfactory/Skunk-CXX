#include <thread>
#include <vector>
#include <functional>

#include "gtest/gtest.h"
#include "block_queue.h"

GTEST_TEST(block_queue_test, simple){
  skunk::BlockQueue<int> queue;
  queue.put(1);
  EXPECT_EQ(1, queue.take());
}

GTEST_TEST(block_queue_test, simple_cocurrent_insert){
  skunk::BlockQueue<int> queue;
  
  std::thread first([](skunk::BlockQueue<int> * q){q -> put(1);}, &queue);
  std::thread second([](skunk::BlockQueue<int> * q){q -> put(2);}, &queue);

  first.join();
  second.join();

  std::vector<int> result;
  result.push_back(queue.take());
  result.push_back(queue.take());

  EXPECT_EQ((std::vector<int>{1,2}), result);
}



int main(int argc, const char** argv) {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
