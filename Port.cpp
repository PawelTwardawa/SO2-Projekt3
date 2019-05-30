#pragma once

#include "Port.hpp"


Port::Port(int nC, int nT, int nP, Ocean * o)
{
    numberCrunes = nC;
    numberTrucks = nT;
    numberOfPlaces = nP;
    ocean = o;

    for(int i = 0; i < numberCrunes; i++)
    {
        cranes.push_back(new Crane(i, o->arr_ships.size(), i *2 ));
    }

    for(int i = 0; i < numberTrucks; i++)
    {
        trucks.push_back(new Truck(i, 1));
    }
}

