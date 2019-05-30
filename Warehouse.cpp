#pragma once

#include "Warehouse.hpp"
#include <stdlib.h>

Warehouse::Warehouse()
{
    int r = rand() % 4 + 1;
    switch (r)
    {
    case 1:
        windDirection = 'S';
        break;
    case 2:
        windDirection = 'N';
        break;
    case 3:
        windDirection = 'E';
        break;
    default:
        windDirection = 'W';
        break;
    }   
    sizeX = 50;
    sizeY = 50;

    roadX = 5;
    roadY = 10;
    roadLength = 20;
    numRoads = 1;

}

Warehouse::Warehouse(char wD, int X, int Y, int rL, int nR)
{
    windDirection = wD;
    sizeX = 50;
    sizeY = 50;

    roadX = X;
    roadY = Y;
    roadLength = rL;
    numRoads = nR;
}

void Warehouse::ChangeConditions()
{
    int r = rand() % 4 + 1;
    switch (r)
    {
    case 1:
        windDirection = 'S';
        break;
    case 2:
        windDirection = 'N';
        break;
    case 3:
        windDirection = 'E';
        break;
    default:
        windDirection = 'W';
        break;
    }   
}