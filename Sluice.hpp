//Śluza będzie tylko do blokowania
//Jak jest wolna(mutex nie jest zablokowany) to statek przez nią przepływa
//śluza ma swoją pozycję, do wykrywania przez statki czy przez nią nie przepływają

#pragma once

#include "mutex"

class Sluice
{
    public:
        std::mutex mSluice;
        int x;  //pozycja śluzy na mapie
        int y;
        int len;

        Sluice(int X, int Y);
};