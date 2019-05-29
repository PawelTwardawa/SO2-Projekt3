//Śluza będzie tylko do blokowania
//Jak jest wolna(mutex nie jest zablokowany) to statek przez nią przepływa

#pragma once

class Sluice
{
    public:
        std::mutex mSluice;

        Sluice();
};