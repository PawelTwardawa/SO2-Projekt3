//Klasa Warehouse będzie odpowiadać za część lądową.
//
#pragma once

#include <mutex>
#include <atomic>
#include <vector>

class Ship;

class Warehouse
{
public:
    //std::atomic<char> windDirection;
    char windDirection;
    int sizeX;
    int sizeY;
    std::mutex mutexWarh;
    int roadX;                      //parametry drogi
    int roadY;
    int roadLength;
    int numRoads;                   //ilość pasów jednej jezdni

    std::array<int, 10> *arr;
    //std::array<std::array<std::atomic<int>, 50>, 50> arr_ships;
    std::array<std::array<int, 50>, 50> arr_trucks;
    //std::atomic<std::array<std::array<Ship, 10>, 10>> **ships_arr;

    Warehouse();
    Warehouse(char wD, int X, int Y, int rL, int nR);

    void ChangeConditions();
};