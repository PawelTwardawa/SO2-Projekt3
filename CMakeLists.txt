cmake_minimum_required(VERSION 3.14)
project(PortWodny)

set(CMAKE_CXX_STANDARD 11)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -lncurses -Wall -Wextra -Wconversion -pedantic") 

set(SOURCES main.cpp Ship.cpp Ship.hpp Truck.cpp Truck.hpp Crane.cpp Crane.hpp Ocean.cpp Ocean.hpp WaterGate.cpp WaterGate.hpp Ui.cpp Ui.hpp Sluice.cpp Sluice.hpp Warehouse.hpp Warehouse.cpp TrafficLights.hpp TrafficLights.cpp)



add_executable(program ${SOURCES})

target_link_libraries(program ncurses)

#target_link_libraries(PortWodny pthread)
