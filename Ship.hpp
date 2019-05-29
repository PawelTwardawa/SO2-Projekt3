//Statek będzie posiadał: nr, prędkość pływania, pojemność, pozycja x i y
#pragma once

#include "Ocean.hpp"
#include <thread>

class Ship
{
    public:
        std::thread t;
        int nr;
        int capacity;
        int x;
        int y;
        int wind;
        int wave;
        int storm;
        float speed;
        Ocean * ocean;
        bool isSailInSluice;

        Ship(int N, int C, int X, int Y, float S, Ocean * o);// : t(&Ship::Move, this){};
        void Move();
};