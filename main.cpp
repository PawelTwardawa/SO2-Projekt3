#include <iostream>
#include <stdlib.h>
#include <thread>
#include <mutex>
#include <ncurses.h>

//Program dostaje ilość statków, ilość żurawi i ilość ciężarówek

int main(int argc, char* argv[])
{
    srand(time(NULL));
    printf("Wypłyńmy na głębię i popłyńmy z nurtem rzeki!\n");
    
    if(argc == 4)
    {
        int numberShips = atoi(argv[1]);
        int numberCranes = atoi(argv[2]);
        int numberTrucks = atoi(argv[3]);

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
        
    }
    else
    {
        std::cout << "Podałeś złą liczbę dnaych. Wprowadź: ilość statków, ilość żurawi i ilość ciężarówek.\n";
    }
    

    return 0;
}
