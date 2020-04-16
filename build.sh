#!/bin/bash 

# only for test 
rm -rf build && mkdir build && cd build && cmake .. && make && make test 

