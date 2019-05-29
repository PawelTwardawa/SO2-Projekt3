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
        int track;              //tor po którym porusza się statek
        int wind;
        int wave;
        int storm;
        float speed;
        Ocean * ocean;
        bool isSailInSluice;    //czy statek płynie w śluzie
        char dirC;              //kierunek płynięcia statku W, E

        Ship(int N, int C, int X, int Y, float S, Ocean * o);// : t(&Ship::Move, this){};
        void Move();
        void MoveToSluice();
};