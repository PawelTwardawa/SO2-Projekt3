#include "Ocean.hpp"

#include <map>
#include <ncurses.h>
#include <thread>

class Ui
{
    public:
        Ocean * ocean;
        Ui(Ocean * o);
        ~Ui();
        void Update();
        
};