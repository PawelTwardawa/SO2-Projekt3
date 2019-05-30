//Statek będzie posiadał: nr, prędkość pływania, pojemność, pozycja x i y
#pragma once

#include "Ocean.hpp"
#include "Port.hpp"
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
        Port * port;
        bool isSailInSluice;    //czy statek płynie w śluzie
        char dirC;              //kierunek płynięcia statku W, E
        bool canMove;
        bool waitForCrane;

        Ship(int N, int C, int X, int Y, float S, Ocean * o, Port * p);// : t(&Ship::Move, this){};
        void Move();
        void MoveToSluice();
        void MoveFromSluice();
        void MoveToCrane(int x, int y);
        void MoveToPoint(int dx, int dy);
};