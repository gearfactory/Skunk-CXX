cmake_minimum_required(VERSION 3.10)

project(skunk)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(skunk STATIC
${CMAKE_CURRENT_SOURCE_DIR}/thread.cc 
${CMAKE_CURRENT_SOURCE_DIR}/threadpool.cc
)