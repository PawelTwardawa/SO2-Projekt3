//Klasa Ocean będzie odpowiadać za przechowywanie wartości na temat kierunku wiatru, wysokości fal i sztormu.
//Współczynnik poruszania będzie wyliczany na podstawie 3+/-(kierunek wiatru) / (wysokość fal + współczynnik sztormu)
//Kierunek wiatru daje +2(ten sam kierunek), -2(przeciwny kierunek), 0(prostopadły).
//Wartości wiatru: N, W, S, E
//Wysokość fal: 1-7
//Współczynnik sztormu: 0(brak sztormu), 1(słaby sztorm), 2(sztorm), 3(silny sztorm)
#pragma once

#include <mutex>
#include <atomic>
#include <vector>
//#include "Ship.hpp"
#include "Sluice.hpp"

struct str_ship
{
    int id;
    int x;
    int y;
};


class Ship;

class Ocean
{
public:
    std::atomic<char> windDirection;
    std::atomic<short> waveHight;
    std::atomic<short> stormValue;
    std::mutex m;
    Sluice *sluiveO;
    int length;

    std::array<int, 10> *arr;
    //std::array<std::array<std::atomic<int>, 50>, 50> arr_ships;
    std::array<std::array<int, 50>, 50> arr_ships;
    //std::atomic<std::array<std::array<Ship, 10>, 10>> **ships_arr;

    Ocean();
    Ocean(char wD, short wH, short sV);
};