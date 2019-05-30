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
    sizeX = 15;
    sizeY = 50;
}

Warehouse::Warehouse(char wD)
{
    windDirection = wD;
    sizeX = 15;
    sizeY = 50;
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