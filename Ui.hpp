#include "Ocean.hpp"
#include "Warehouse.hpp"

#include <map>
#include <ncurses.h>
#include <thread>

class Ui
{
    public:
        Ocean * ocean;
        Warehouse *warehouse;
        Ui(Ocean * o, Warehouse *w);
        ~Ui();
        void Update();
        
};