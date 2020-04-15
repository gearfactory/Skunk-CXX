cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_FLAGS "-std=gnu++11")
project("skunk-core")

include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_library(skunk
  "eventloop.cc"
)
target_link_libraries(skunk pthread)

