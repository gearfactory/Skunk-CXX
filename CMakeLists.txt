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
    PUBLIC "${GOOLETESTDIR}/googletest/include"
  )

  # FIXME: should make a cmake function to generate the test as function 
  # test skunk/buffer.h
  add_executable(buffer_test "tests/buffer_test.cc")
  target_link_libraries(buffer_test gtest pthread)
  add_test(buffer_test_routine buffer_test)

  
endif()

add_subdirectory("skunk")


