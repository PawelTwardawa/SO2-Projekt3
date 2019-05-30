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
        Ui(Ocean * o, Port * p);
        ~Ui();
        void Update();
        
};