//Statek będzie posiadał: nr, prędkość pływania, pojemność, pozycja x i y

class Ship
{
public:
    int nr;
    int capacity;
    int x;
    int y;
    float speed;

    Ship(int N, int C, int X, int Y, float S);
};