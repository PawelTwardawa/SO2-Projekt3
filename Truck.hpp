//Ciężarówka jest także blokowana przez statek.
//Może jakiś magazyn też ją będzie blokować, żeby ją rozładowywał?
//Może być zablokowana przez statek tylko jeśli jest pusta, może być rozładowana przez magazyn jeśli jest załadowana

#include "Warehouse.hpp"

class Truck 
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
    char dirC;                                  //kierunek jazdy ciężarówki
    std::thread threadT;
    int timeOperation;                          //czas operacji rozładunku/załadunku


    Truck(int N, int C, int X, int Y, int s, float sp, Warehouse* w, char dC), int tO;
    void Load();
    void Unload();
    void Move();
};