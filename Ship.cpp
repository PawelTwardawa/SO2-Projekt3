#pragma once

#include "Ship.hpp"
#include <cmath>
#include <thread>
#include <stdlib.h>

Ship::Ship(int N, int C, int X, int Y, float S, Ocean * o)
{
    nr = N;
    capacity = C;
    x = X;
    y = Y;
    speed = S;
    ocean = o;
    wind =1;
    storm =1;
    wave =1;
    t = std::thread(&Ship::Move, this);
    isSailInSluice = false;
}

void Ship::Move()
{
    while (true)
    {
        double dx = x + speed - (wind + wave + storm)/10;
        bool moved = false;

        double dy = y +  rand() % 3 - 1; //tu sie zmieni zaleznie od prametrow morza

        
        while(!moved)
        {
            if(isSailInSluice)
            {
                //sprawdzamy czy statek nie jest poza śluzą, żeby ją odblokować
                if(x > ocean->sluiveO->x + ocean->sluiveO->len)
                {
                    isSailInSluice = false;
                    ocean->sluiveO->mSluice.unlock();
                }
            }
            else
            {
                if(x == ocean->sluiveO->x)
                {
                    isSailInSluice = true;
                    ocean->sluiveO->mSluice.lock();
                }
            }
            
            ocean->m.lock();
            if(ocean->arr_ships[ceil(dx)][ceil(dy)] == 0)
            {
                moved = true;

                
                ocean->arr_ships[ceil(dx)][ceil(dy)] = nr;
                ocean->arr_ships[x][y] = 0;
                x = ceil(dx);
                y = ceil(dy);
            }
            else
            {
                //std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }

            ocean->m.unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
}