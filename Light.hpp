//Ciężarówka jest także blokowana przez statek.
//Może jakiś magazyn też ją będzie blokować, żeby ją rozładowywał?
//Może być zablokowana przez statek tylko jeśli jest pusta, może być rozładowana przez magazyn jeśli jest załadowana
//Ciężarówki mają ograniczenie prędkości i nie mogą się ścigać
#include "Warehouse.hpp"
#include "TrafficLights.hpp"
#include <thread>

class Light 
{
public:
    int nr;
    int capacity;
    bool isFull;
    int status;                                 //procent postępu funkcji załadunku/rozładunku
    int x;
    int y;
    float speed;
    Warehouse* warH;
    TrafficLights* tLights;
    char dirC;                                  //kierunek jazdy ciężarówki
    std::thread threadT;
    int timeOperation;                          //czas operacji rozładunku/załadunku
};