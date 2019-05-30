#include "Crane.hpp"
#include <thread>

Crane::Crane(int N, int px, int py)
{
    nr = N;
    x = px;
    y = py;
}

void Crane::Do()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}