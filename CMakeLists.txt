cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_FLAGS "-std=gnu++11")
project("skunk")

option(SKUNK_UNIT_TEST "build skunk unit test" ON)

if(SKUNK_UNIT_TEST)
  enable_testing()
  message("Start to build skunk unit tests -_-")

  set(GOOLETESTDIR "third_party/googletest")
  # add google test 
  add_subdirectory(${GOOLETESTDIR})

  include_directories(
    PUBLIC "skunk/include"
    PUBLIC "skunk"
    PUBLIC "${GOOLETESTDIR}/googletest/include"
  )

  function(SKUNK_TEST testname testfile)
    add_executable(${testname} ${testfile})
    target_link_libraries(${testname} gtest pthread skunk)
    add_test(${testname} ${testname})
  endfunction(SKUNK_TEST)
  
  
  # test skunk/buffer.cc
  SKUNK_TEST(buffer_test "tests/buffer_test.cc")

  # test skunk/eventloop.cc
  SKUNK_TEST(eventloop_test "tests/eventloop_test.cc")

  # test skunk/block_queue.h
  SKUNK_TEST(block_queue_test "tests/block_queue_test.cc")


  
endif()

add_subdirectory("skunk")


