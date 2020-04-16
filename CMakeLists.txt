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

  # FIXME: should make a cmake function to generate the test as function 
  
  # test skunk/buffer.cc
  add_executable(buffer_test "tests/buffer_test.cc")
  target_link_libraries(buffer_test gtest pthread skunk)
  add_test(buffer_test buffer_test)

  # # test skunk/eventloop.cc
  add_executable(eventloop_test "tests/eventloop_test.cc")
  target_link_libraries(eventloop_test gtest pthread skunk)
  add_test(eventloop_test eventloop_test)

  add_executable(block_queue_test "tests/block_queue_test.cc")
  target_link_libraries(block_queue_test gtest pthread skunk)
  add_test(block_queue_test block_queue_test)

  
endif()

add_subdirectory("skunk")


