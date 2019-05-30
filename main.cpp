#include <iostream>
#include <stdlib.h>
#include <thread>
#include <mutex>
#include <ncurses.h>

#include "Ocean.hpp"
#include "Ship.hpp"
#include "Ui.hpp"
#include "Sluice.hpp"
#include "Port.hpp"


//Program dostaje ilość statków, ilość żurawi i ilość ciężarówek

std::vector<Ship*> ships;
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
        if(5 > numberShips || numberShips > 30 || 5 > numberCranes || numberCranes > 10 || 5 > numberTrucks || numberTrucks > 10)
        {
            std::cout << "Wprowadzane liczby muszą być większe niż 5 i nie większe niż 10.\n";
            return -2;
        }

        
    }
    else
    {
        std::cout << "Podałeś złą liczbę dnaych. Wprowadź: ilość statków, ilość żurawi i ilość ciężarówek.\n";
        return 0;
    }

    Ocean *ocean = new Ocean('W', 1, 1);
    Port * port = new Port(numberCranes, numberTrucks, 5, ocean);


    for(int i = 0; i < numberShips; i++)
    {
        Ship *s = new Ship(i +1, 2,1, i+6, 1, ocean, port);
        ships.push_back(s);
    }

        //ships.push_back(new Ship(6, 1,1, 6+6, 1, ocean, port)); //dodatkowe statki
        //ships.push_back(new Ship(7, 5,1, 7+6, 1, ocean, port)); 

    std::thread tu(&Ui::Update, new Ui(ocean, port, &ships));
    std::cout<< "koniec";
    tu.join();
    std::cout<< "koniec";
    for(auto s : ships)
    {
        s->t.join();
    }

    std::cout<< "koniec";
    endwin();

    return 0;
}
