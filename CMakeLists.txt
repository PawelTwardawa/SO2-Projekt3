cmake_minimum_required(VERSION 3.14)
project(PortWodny)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -lncurses") 

set(SOURCES main.cpp)
add_executable(program ${SOURCES})

#target_link_libraries(PortWodny pthread)
