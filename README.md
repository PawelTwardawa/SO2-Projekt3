# SO_proj3
Autorzy:
Paweł Twardawa
Przemysław Wujek

# Tworzenie CMake

cmake_minimum_required(VERSION 3.14)
project(Filozofowie_etap3)        //nazwa projektu

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -lncurses") //tutaj dołączamy bibliotekę pthread i ncurses

set(SOURCES )//tutaj wpisujemy jakie źródła będą w projekcie, czyli nasze pliki .cpp i .hpp
add_executable(program ${SOURCES})

\#target_link_libraries(Filozofowie_etap3 pthread)


Aby zbudować CMake wpisz w konsoli "cmake ./".
Aby zbudować program wpisz w konsoli "make".
