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
    track = x;
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
        dx = x + (speed - (wind + wave + storm)/10) * direction;
        moved = false;
        dy = y;//+  rand() % 3 - 1; //tu sie zmieni zaleznie od prametrow morza

        while(!moved)
        {
            if(!isSailInSluice)
            {
                if((x == ocean->sluiveO->x-2 && dirC == 'E') || (x == ocean->sluiveO->x + ocean->sluiveO->len + 2 && dirC == 'W'))
                {
                    isSailInSluice = true;
                    ocean->sluiveO->mSluice.lock();
                    //dy = ocean->sluiveO->y;
                    //x++;                                    //statek wpływa do śluzy
                    //MoveToSluice();                         //tutaj uruchamiam metodę zjeścia do śluzy
                }
            }
            else
            {
                //sprawdzamy czy statek nie jest poza śluzą, żeby ją odblokować
                if((x == ocean->sluiveO->x + ocean->sluiveO->len && dirC == 'E') || (x == ocean->sluiveO->x-1 && dirC == 'W')) 
                {
                    isSailInSluice = false;
                    ocean->sluiveO->mSluice.unlock();
                    //dy = track;
                    //tutaj uruchamiam metodę powrotu do swojego toru
                }
            }
            
            ocean->m.lock();
            if(ocean->arr_ships[ceil(dx)][ceil(dy)] == 0)
            {
                moved = true;

                
                ocean->arr_ships[ceil(dx)][ceil(dy)] = nr;
                ocean->arr_ships[x][y] = 0;
                
                //if(!isSailInSluice)
                {
                    y = ceil(dy);
                }
                //else
                {
                    //y = ocean->sluiveO->y;
                }
                
                x = ceil(dx);
            }
            else
            {
                //std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }

            ocean->m.unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
    
}

void Ship::MoveToSluice()
{
    double dy;
    short direction = 1;

    if(y > ocean->sluiveO->y)
        direction = -1;

    do
    {
        ocean->m.lock();
        dy = y + 1 * direction; //tu sie zmieni zaleznie od prametrow morza
        //jeśli jest niżej niż śluza
        
        if(ocean->arr_ships[x][ceil(dy)] == 0)
        {    
            ocean->arr_ships[x][ceil(dy)] = nr;
            ocean->arr_ships[x][y] = 0;
            y = ceil(dy);
        }
        else
        {
            //std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        ocean->m.unlock();
    }while (y != ocean->sluiveO->y);
    
    
}