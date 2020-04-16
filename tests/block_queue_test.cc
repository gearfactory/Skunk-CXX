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

GTEST_TEST(block_queue_test, cocurrent_insert){
  skunk::BlockQueue<int> queue;
  
  std::thread first(std::bind(&skunk::BlockQueue<int>::put, &queue, 1));
  std::thread second(std::bind(&skunk::BlockQueue<int>::put, &queue, 2));

  first.join();
  second.join();

  std::vector<int> result;
  result.push_back(queue.take());
  result.push_back(queue.take());

  //std::move

  EXPECT_EQ((std::vector<int>{1,2}), result);
}

int main(int argc, const char** argv) {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
