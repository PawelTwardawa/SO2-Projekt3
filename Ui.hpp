#include "Ocean.hpp"
#include "Warehouse.hpp"
#include "Port.hpp"


#include <map>
#include <ncurses.h>
#include <thread>

class Ui
{
    public:
        Ocean * ocean;
        Warehouse *warehouse;
        Port * port;
        std::vector<Ship*> *ships;
        Ui(Ocean * o, Port * p, std::vector<Ship*> *ships, Warehouse *w);
        ~Ui();
        void Update();
        
};