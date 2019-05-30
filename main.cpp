#include <iostream>
#include <stdlib.h>
#include <thread>
#include <mutex>
#include <ncurses.h>

#include "Ocean.hpp"
#include "Ship.hpp"
#include "Ui.hpp"
#include "Sluice.hpp"
#include "Truck.hpp"
#include "Warehouse.hpp"
#include "TrafficLights.hpp"

//Program dostaje ilość statków, ilość żurawi i ilość ciężarówek

std::vector<Ship*> ships;
std::vector<Truck*> trucks;
int numberShips;
int numberCranes;
int numberTrucks;


int main(int argc, char* argv[])
{
    

    srand(time(NULL));
    printf("Wypłyńmy na głębię i popłyńmy z nurtem rzeki!\n");
    
    if(argc == 4)
    {
        numberShips = atoi(argv[1]);
        numberCranes = atoi(argv[2]);
        numberTrucks = atoi(argv[3]);

        if(numberShips <= 0 || numberCranes <= 0 || numberTrucks <= 0)
        {
            std::cout << "Wprowadzane liczby muszą być większe od zera!\n";
            return -1;
        }
        if(5 > numberShips || numberShips > 10 || 5 > numberCranes || numberCranes > 10 || 5 > numberTrucks || numberTrucks > 10)
        {
            std::cout << "Wprowadzane liczby muszą być większe niż 5 i nie większe niż 10.\n";
            return -2;
        }

        numberShips = 30;
    }
    else
    {
        std::cout << "Podałeś złą liczbę dnaych. Wprowadź: ilość statków, ilość żurawi i ilość ciężarówek.\n";
        return 0;
    }

    Ocean *ocean = new Ocean('W', 1, 1);
    Warehouse *warehouse = new Warehouse('W', 10, 10, 30, 1); //magazyn 50x50, droga zaczyna się w x=10, kończy w x=10+30, na y=10, ilość pasów = 1
    TrafficLights* trafficLights = new TrafficLights(1);


    for(int i = 0; i < numberShips; i++)
    {
        Ship *s = new Ship(i +1, 2,1, i+6, 1, ocean);
        ships.push_back(s);
    }
    for(int i = 0; i < numberTrucks; i++)
    {
        Truck *t = new Truck(i+1, 1, 1, i+1, 0, 1, warehouse, 'E', 10, trafficLights);
        trucks.push_back(t);
    }

    std::thread tu(&Ui::Update, new Ui(ocean, warehouse));

    tu.join();

    for(auto s : ships)
    {
        s->t.join();
    }
    for(auto t : trucks)
    {
        t->threadT.join();
    }

    return 0;
}
