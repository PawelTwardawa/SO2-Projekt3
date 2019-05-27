#include "Ocean.cpp"
//Klasa Ocean będzie odpowiadać za przechowywanie wartości na temat kierunku wiatru, wysokości fal i sztormu.
//Współczynnik poruszania będzie wyliczany na podstawie 3+/-(kierunek wiatru) / (wysokość fal + współczynnik sztormu)
//Kierunek wiatru daje +2(ten sam kierunek), -2(przeciwny kierunek), 0(prostopadły).
//Wartości wiatru: N, W, S, E
//Wysokość fal: 1-7
//Współczynnik sztormu: 0(brak sztormu), 1(słaby sztorm), 2(sztorm), 3(silny sztorm)

class Ocean
{
public:
    char windDirection;
    short waveHight;
    short stormValue;

    Ocean();
    Ocean(char wD, short wH, short sV);
}