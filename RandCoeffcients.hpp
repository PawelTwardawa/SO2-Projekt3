#pragma once

#include "Ocean.hpp"
#include <thread>
#include <atomic>

class RandCoeffcients
{
public:
    int time;
    Ocean *ocean;

    RandCoeffcients(int t, Ocean *o);
    void RandW();
};