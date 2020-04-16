#include "gtest/gtest.h"
#include "skunk/buffer.h"


GTEST_TEST(skunk_buffer_test, simple){
  EXPECT_EQ(1, 1);
}

int main(int argc, const char** argv) {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}