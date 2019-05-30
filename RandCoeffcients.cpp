#include "RandCoeffcients.hpp"

RandCoeffcients::RandCoeffcients(int t, Ocean *o)
{
    ocean = o;
    time = t;
}

void RandCoeffcients::RandW()
{
    while (true)
    {
        ocean->stormValue = rand() % 4;
        ocean->waveHight = rand() % 7 + 1;

        int r = rand() % 4 + 1;
        switch (r)
        {
        case 1:
            ocean->windDirection = 'S';
            break;
        case 2:
            ocean->windDirection = 'N';
            break;
        case 3:
            ocean->windDirection = 'E';
            break;
        default:
            ocean->windDirection = 'W';
            break;
        }   

        std::this_thread::sleep_for(std::chrono::milliseconds(4000 * time + (rand() % 100)));
    }    
}