#include "RandCoeffcients.hpp"

RandCoeffcients::RandCoeffcients(int t, Ocean *o)
{
    ocean = o;
    time = t;
}

void RandCoeffcients::Rand()
{
    while (true)
    {
        ocean->stormValue = rand() % 4;
        ocean->waveHight = rand() % 7 + 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(4000 * timeOperation + (rand() % 100)));
    }    
}