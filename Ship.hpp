//Statek będzie posiadał: nr, prędkość pływania, pojemność, pozycja x i y
#pragma once

#include "Ocean.hpp"

class Ship
{
    public:
        int nr;
        int capacity;
        int x;
        int y;
        float speed;
        Ocean * ocean;

        Ship(int N, int C, int X, int Y, float S, Ocean * o);
        void Move(int wind, int wave, int storm);
};