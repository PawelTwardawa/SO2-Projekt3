#pragma once
//Ciężarówka blokuje światła, żeby wjechać na drogę
#include <mutex>

class TrafficLights 
{
public:
    int valRoads;                                //ilość pasów
    std::mutex mRoad;

    TrafficLights(int vR);
};