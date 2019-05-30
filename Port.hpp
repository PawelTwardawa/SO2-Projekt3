#pragma once

#include <vector>
#include <atomic>
#include "Truck.hpp"
#include "Crane.hpp"
#include "Ocean.hpp"

class Port
{
    public:
        int numberOfPlaces;
        int numberCrunes;
        int numberTrucks;
        Ocean * ocean;

        std::vector<Crane*> crunes;
        std::vector<Truck*> trucks;

        Port(int nC, int nT, int nP, Ocean * ocean);
};