#include "Truck.cpp"
//Ciężarówka jest także blokowana przez statek.
//Może jakiś magazyn też ją będzie blokować, żeby ją rozładowywał?
//Może być zablokowana przez statek tylko jeśli jest pusta, może być rozładowana przez magazyn jeśli jest załadowana

class Truck 
{
public:
    int nr;
    int capacity;
    bool isFull;

    Truck(int N, int C);
}