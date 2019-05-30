#include "Ocean.hpp"
#include "Port.hpp"

#include <map>
#include <ncurses.h>
#include <thread>

class Ui
{
    public:
        Ocean * ocean;
        Port * port;
        std::vector<Ship*> *ships;
        Ui(Ocean * o, Port * p, std::vector<Ship*> *ships);
        ~Ui();
        void Update();
        
};