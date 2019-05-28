#pragma once

#include "Ship.hpp"
#include <cmath>
#include <thread>

Ship::Ship(int N, int C, int X, int Y, float S, Ocean * o)
{
    nr = N;
    capacity = C;
    x = X;
    y = Y;
    speed = S;
    ocean = o;
}

void Ship::Move(int wind, int wave, int storm)
{
    while (true)
    {
        double dx = x + speed - (wind + wave + storm)/10;
        x = ceil(dx);

        

        //(ocean->ships_arr)[0][0]->x

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
}