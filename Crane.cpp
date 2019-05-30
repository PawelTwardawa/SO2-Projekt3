#include "Crane.hpp"
#include <thread>

Crane::Crane()
{
    
}

Crane::Crane(int N, int px, int py)
{
    nr = N;
    x = px;
    y = py;
}

void Crane::Do()
{
    isUsed = true;
    while(!haveTruck)
    {
        status = CraneStatus::WitingForTruck;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));


    isUsed = false;
}