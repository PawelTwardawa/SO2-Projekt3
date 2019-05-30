#pragma once
//Ciężarówka jest także blokowana przez statek.
//Może jakiś magazyn też ją będzie blokować, żeby ją rozładowywał?
//Może być zablokowana przez statek tylko jeśli jest pusta, może być rozładowana przez magazyn jeśli jest załadowana
//Ciężarówki mają ograniczenie prędkości i nie mogą się ścigać
#include "Warehouse.hpp"
#include "TrafficLights.hpp"
#include "Port.hpp"

#include <thread>
#include <atomic>

class Port;

class Truck 
{
public:
    int nr;
    int capacity;
    bool isFull;
    int status;                                 //procent postępu funkcji załadunku/rozładunku
    std::atomic<int> x;                         
    std::atomic<int> y;
    float speed;
    Warehouse* warH;
    TrafficLights* tLights;
    char dirC;                                  //kierunek jazdy ciężarówki
    std::thread threadT;
    int timeOperation;                          //czas operacji rozładunku/załadunku
    Port * port;


    Truck(int N, int C, int X, int Y, int s, float sp, Warehouse* w, char dC, int tO, TrafficLights* tL, Port * p);
    void Load();
    void Move();
    void EntryWarehouse();
    void EntryHarbor();
    void EntryRoad();
    void MoveToPoint(int x, int y);
    void MoveToPointV2(int x, int y);
    void MoveToCrane(int x, int y);
};