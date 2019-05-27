#include "Ocean.hpp"
#include <stdlib.h>

Ocean::Ocean()
{
    int r = rand() % 4 + 1;
    switch (r)
    {
    case 1:
        windDirection = "S";
        break;
    case 2:
        windDirection = "N";
        break;
    case 3:
        windDirection = "E";
        break;
    default:
        windDirection = "W";
        break;
    }   
    
    waveHight = rand() % 7 + 1;
    stormValue = rand() % 3 + 1;
}

Ocean::Ocean(char wD, short wH, short sV)
{
    windDirection = wD;
    waveHight = wH;
    stormValue = sV;
}