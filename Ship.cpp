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
    track = Y;
    dirC = 'E';
}

void Ship::Move()
{
    double dx;
    bool moved;
    double dy;
    short direction = 1; //zmienna odpowiedzialna za kierunek płynięcia statku, 1 to prawo, -1 to lewo
    
    while (true)
    {
        if((x >= ocean->length-1 && dirC == 'E') || (x <= 2 && dirC == 'W')) // statek zawraca
        {
            direction *= -1;
            if(dirC == 'E')
                dirC = 'W';
            else
                dirC = 'E';
        }

        if(!isSailInSluice)
        {
            if((x == ocean->sluiveO->x-3 && dirC == 'E') || (x == ocean->sluiveO->x + ocean->sluiveO->len + 3 && dirC == 'W'))
            {
                isSailInSluice = true;
                ocean->sluiveO->mSluice.lock();
                //wyrównanie do poziomu śluzy 
                MoveToSluice();
            }
        }
        else
        {
            //sprawdzamy czy statek nie jest poza śluzą, żeby ją odblokować
            if((x == ocean->sluiveO->x + ocean->sluiveO->len+1 && dirC == 'E') || (x == ocean->sluiveO->x-1 && dirC == 'W')) 
            {
                isSailInSluice = false;
                ocean->sluiveO->mSluice.unlock();
                //tutaj uruchamiam metodę powrotu do swojego toru
                MoveFromSluice();
            }
        }

        dx = x + (speed - (wind + wave + storm)/10) * direction;
        moved = false;
        dy = y;//+  rand() % 3 - 1; //tu sie zmieni zaleznie od prametrow morza


        while(!moved)
        {
            ocean->m.lock();

            if(ocean->arr_ships[ceil(dx)][ceil(dy)] == 0)
            {
                moved = true;

                ocean->arr_ships[ceil(dx)][ceil(dy)] = nr;
                ocean->arr_ships[x][y] = 0;
                
                y = ceil(dy);
                x = ceil(dx);
            }
            else
            {
                //std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }

            ocean->m.unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(150 + (rand() % 100)));
    }
    
}

void Ship::MoveToSluice()
{
    double dy;
    double dx;
    int dir = 1;
    bool moved;

    if(y > ocean->sluiveO->y)
        dir = -1;
    if(dirC == 'E')
        dx = x + 1;
    else 
        dx = x - 1;

    while (y - ocean->sluiveO->y != 0)
    {
        moved = false;
        dy = y+(1*dir); 
        
        while(!moved)
        {
            ocean->m.lock();

            if(ocean->arr_ships[ceil(dx)][ceil(dy)] == 0)
            {
                moved = true;

                ocean->arr_ships[ceil(dx)][ceil(dy)] = nr;
                ocean->arr_ships[x][y] = 0;
                
                y = ceil(dy);
                x = ceil(dx);
            }
            else
            {
                //std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }

            ocean->m.unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(150 + (rand() % 100)));
    }
}

void Ship::MoveFromSluice()
{
    double dy;
    double dx;
    int dir = 1;
    bool moved;

    if(y > track)
        dir = -1;
    dx = x;
    while (y - track != 0)
    {
        moved = false;
        dy = y+(1*dir); 
        
        while(!moved)
        {
            ocean->m.lock();

            if(ocean->arr_ships[ceil(dx)][ceil(dy)] == 0)
            {
                moved = true;

                ocean->arr_ships[ceil(dx)][ceil(dy)] = nr;
                ocean->arr_ships[x][y] = 0;
                
                y = ceil(dy);
                x = ceil(dx);
            }
            else
            {
                //std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }

            ocean->m.unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(150 + (rand() % 100)));
    }
}