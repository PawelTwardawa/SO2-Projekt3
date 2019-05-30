#include "Truck.hpp"

#include <cmath>
#include <stdlib.h>
#include <unistd.h>

Truck::Truck(int N, int C, int X, int Y, int s, float sp, Warehouse* w, char dC, int tO, TrafficLights* tL, Port * p)
{
    isFull = false;
    nr = N;
    capacity = C;
    status = s;
    x = X;
    y = Y;
    speed = sp;
    warH = w;
    dirC = dC; 
    timeOperation = tO;
    threadT = std::thread(&Truck::Move, this);
    tLights = tL;
    port = p;
}

void Truck::Load()
{
    for(int i = 0; i < port->cranes.size(); i++)
    {
        if(!port->cranes[i]->mutex.try_lock())
        {
            MoveToCrane(port->cranes[i]->x, port->cranes[i]->y);
        }
        else
        {
            port->cranes[i]->mutex.unlock();
        }
        
    }

    // int div = 10;
    // for(int i; i<div; i++)
    // {
    //     std::this_thread::sleep_for(std::chrono::milliseconds(timeOperation/div));
    //     status += 100/div;
    // }
    // status = 0;
}

// void Truck::Unload()
// {
//     int div = 10;
//     for(int i; i<div; i++)
//     {
//         //std::this_thread::sleep_for(std::chrono::milliseconds(timeOperation/div));
//         status += 100/div;
//     }
//     status = 0;
// }

void Truck::MoveToPoint(int dx, int dy)
{
    bool moved = false;
    while(!moved)
    {
        warH->mutexWarh.lock();

        if(warH->arr_trucks[ceil(dx)][ceil(dy)] == 0)
        {
            moved = true;

            warH->arr_trucks[ceil(dx)][ceil(dy)] = nr;
            warH->arr_trucks[x][y] = 0;
            
            y = ceil(dy);
            x = ceil(dx);
        }
        else
        {
            //std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        warH->mutexWarh.unlock();
    }
    
}

void Truck::MoveToPointV2(int dx, int dy)
{
    bool moved = false;

    //dopoki nie zmiani pozycji, czeka
    while(!moved)
    {
        warH->mutexWarh.lock();

        if(warH->arr_trucks[ceil(dx)][ceil(dy)] == 0)
        {
            moved = true;

            warH->arr_trucks[ceil(dx)][ceil(dy)] = nr;
            warH->arr_trucks[x][y] = 0;
            
            y = ceil(dy);
            x = ceil(dx);
        }
        //jezeli pozycja dx, dy jest zajeta omijamy ja albo gora albo dolem
        else if(warH->arr_trucks[ceil(dx)][ceil(dy - 1)] == 0)
        {
            moved = true;

            warH->arr_trucks[ceil(dx)][ceil(dy -1)] = nr;
            warH->arr_trucks[x][y] = 0;
            
            y = ceil(dy -1 );
            x = ceil(dx);
        }
        else if(warH->arr_trucks[ceil(dx)][ceil(dy + 1)] == 0)
        {
            moved = true;

            warH->arr_trucks[ceil(dx)][ceil(dy +1)] = nr;
            warH->arr_trucks[x][y] = 0;
            
            y = ceil(dy +1 );
            x = ceil(dx);
        }
        
        warH->mutexWarh.unlock();
    }
}

void Truck::MoveToCrane(int _x, int _y)
{
    double dx;
    double dy;
    bool moved;
    

    //MoveToPoint(x - 1, y);
    //dopoki statek nie doplynie do zurawia
    while (x != _x || y != _y)
    {
        moved = false;
        //sprawdzamy w ktorej osi ma dalej do celu
        if(std::abs(x - _x) >=  std::abs(y - _y))
        {
            if(x > _x)
            {
                dx = x -1;
            }
            else
            {
                dx = x+1;
            }
            dy = y;
        }
        else 
        {
             dx = x;
             if(y > _y)
             {
                 dy = y -1;
             }
             else
             {
                dy = y +1;
             }
        }        
        MoveToPointV2(dx, dy);

        std::this_thread::sleep_for(std::chrono::milliseconds(150 + (rand() % 100)));
    }
    //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}


void Truck::Move()
{
    double dx;
    bool moved;
    double dy;
    short direction = 1; //zmienna odpowiedzialna za kierunek jazdy ciężarówki, 1 to prawo, -1 to lewo
    
    while (true)
    {
        // if(x <= warH->roadX && dirC == 'W')
        // {
        //     for(int i = 0; i < port->cranes.size(); i++)
        //     {
        //         if(!port->cranes[i]->mutex.try_lock())
        //         {
        //             MoveToCrane(port->cranes[i]->x - warH->arr_trucks.size() + 1, port->cranes[i]->y);
        //         }
        //         else
        //         {
        //             port->cranes[i]->mutex.unlock();
        //         }
                
        //     }
        //    //std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
        // }
        // else 
        if((x >= warH->roadX+warH->roadLength+2 && dirC == 'E') || (x <= warH->roadX-2 && dirC == 'W')) // ciężarówka zawraca
        {
            direction *= -1;
            if(dirC == 'E')
            {
                EntryWarehouse();
                dirC = 'W';
            }
            else
            {
                EntryHarbor();
                dirC = 'E';
            }
        }


                
    
        
        else
        {
            

            dx = x + 1 * direction;
            moved = false;
            dy = y;

            if(x == warH->roadX-3 && dirC == 'E')//wyjazd z portu, ciężarówka czeka na pozwolenie wyjazdu
            {
                tLights->mRoad.lock();
                
                {
                    EntryRoad();
                }
                tLights->mRoad.unlock();
            }
            else
            {

                MoveToPoint(dx, dy);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(150 + (rand() % 100)));
        }
    }
}


void Truck::EntryWarehouse() //rozpoczyna rozładunek, po wyjeździe ciężarówka jest pas wyżej
{

    std::this_thread::sleep_for(std::chrono::milliseconds(150*timeOperation + (rand() % 100)));


    warH->mutexWarh.lock();
    warH->arr_trucks[x][y] = 0;
    y = y + 2;
    warH->arr_trucks[x][y] = nr;
    warH->mutexWarh.unlock();
}

void Truck::EntryHarbor() //rozpoczyna załadunek, po wyjeździe ciężarówka jest pas niżej
{

    bool find = false;
    Crane * crane;
    while(!find)
    {
        for(int i = 0; i < port->cranes.size(); i++)
        {
            if(port->cranes[i]->isUsed && !port->cranes[i]->haveTruck)
            {
                crane = port->cranes[i];
                port->cranes[i]->haveTruck = true;
                MoveToCrane(port->cranes[i]->x - warH->arr_trucks.size() + 1, port->cranes[i]->y);
                port->cranes[i]->status = CraneStatus::Working;
                find = true;
                break;
            }
            else
            {
                //port->cranes[i]->mutex.unlock();
            }
            
        }
    }

    while(crane->isUsed)
    {

    }
    crane->haveTruck = false;
    crane->status = CraneStatus::WaitingForShip;
    //std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    // warH->mutexWarh.lock();
    // warH->arr_trucks[x][y] = 0;
    // y = y - 2;
    // warH->arr_trucks[x][y] = nr;
    // warH->mutexWarh.unlock(); 
}

void Truck::EntryRoad()
{
    int dir = 1;
    if(y > warH->roadY)
        dir = -1;

    //ciężarówka przejeżdża na tor do wjazdu na drogę
    warH->mutexWarh.lock();
    warH->arr_trucks[x][y] = 0;
    x = x + 1;
    warH->arr_trucks[x][y] = nr;
    warH->mutexWarh.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(150 + (rand() % 100)));

    while (y != warH->roadY)
    {
        warH->mutexWarh.lock();
        warH->arr_trucks[x][y] = 0;
        //y = y + 1 * dir;
        y.exchange(y+1, std::memory_order::memory_order_acq_rel);
        warH->arr_trucks[x][y] = nr;
        warH->mutexWarh.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(150 + (rand() % 100)));
    }
}