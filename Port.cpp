#pragma once

#include "Port.hpp"


Port::Port(int nC, int nT, int nP, Ocean * o)//, std::vector<Truck*> t)
{
    numberCrunes = nC;
    numberTrucks = nT;
    numberOfPlaces = nP;
    ocean = o;
    //trucks = t;

    for(int i = 0; i < numberCrunes; i++)
    {
        cranes.push_back(new Crane(i, o->arr_ships.size(), i *2 ));
    }

    
}

