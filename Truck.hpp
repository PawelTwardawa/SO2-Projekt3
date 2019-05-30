#pragma once
//Ciężarówka jest także blokowana przez statek.
//Może jakiś magazyn też ją będzie blokować, żeby ją rozładowywał?
//Może być zablokowana przez statek tylko jeśli jest pusta, może być rozładowana przez magazyn jeśli jest załadowana
//Ciężarówki mają ograniczenie prędkości i nie mogą się ścigać
#include "Warehouse.hpp"
#include "TrafficLights.hpp"
#include <thread>
#include <atomic>

class Truck 
{
public:
    int nr;
    int capacity;
    bool isFull;
    int status;                                 //procent postępu funkcji załadunku/rozładunku
    std::atomic<int> x;                         //atomic bo były wyścigi
    std::atomic<int> y;
    float speed;
    Warehouse* warH;
    TrafficLights* tLights;
    char dirC;                                  //kierunek jazdy ciężarówki
    std::thread threadT;
    int timeOperation;                          //czas operacji rozładunku/załadunku


    Truck(int N, int C, int X, int Y, int s, float sp, Warehouse* w, char dC, int tO, TrafficLights* tL);
    void Load();
    void Unload();
    void Move();
    void EntryWarehouse();
    void EntryHarbor();
    void EntryRoad();
};