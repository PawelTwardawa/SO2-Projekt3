#include "Ui.hpp"
#include "Ship.hpp"


Ui::Ui(Ocean * o, Port * p, std::vector<Ship*> *s, Warehouse *w)
{
    ocean = o;
    warehouse = w;
    port = p;


    initscr();
    noecho();
    raw();
    nodelay(stdscr, true);
    start_color();
    use_default_colors();
    curs_set(0);

    ships = s;

}

void Ui::Update()
{
    bool working = true;
    char craneAnim = '\\';
    while (working)
    {

        int c = getch();
        if(c == 113)
        {
            for(auto s : *ships)
            {
                s->working = false;
            }
            //endwin();
            working = false;
            return;
        }

        clrtoeol();
        for(int i = 0; i < ocean->arr_ships.size(); i++)
        {
            for(int j = 0; j < ocean->arr_ships[i].size(); j++)
            {
                if(ocean->arr_ships[i][j] != 0)
                {
                    mvprintw(j, i, "#"); //"%d", ocean->arr_ships[i][j]);
                }
                else
                {
                    if((i < ocean->sluiveO->x || i > ocean->sluiveO->x+ocean->sluiveO->len) || j == ocean->sluiveO->y)
                        mvprintw(j, i, ".");
                    else
                    {
                        mvprintw(j, i, " ");
                    }
                }
            }
        }

        for(int i = 0; i < ocean->arr_ships.size(); i++)
        {
            for(int j=0; j<warehouse->arr_trucks[i].size(); j++)
                {
                    if(warehouse->arr_trucks[i][j] != 0)
                    {
                        mvprintw(j, i + warehouse->arr_trucks[i].size(), "="); //"%d", ocean->arr_ships[i][j]);
                    }
                    else
                    {
                        //tutaj jakieś rysowanie drogi
                        if((j == warehouse->roadY-1 || j == warehouse->roadY+(warehouse->numRoads*2+1) || j == warehouse->roadY+(warehouse->numRoads)) && i >= warehouse->roadY && i <= warehouse->roadY+warehouse->roadLength)
                            mvprintw(j, i + warehouse->arr_trucks[i].size(), "_");
                        else
                        {
                            mvprintw(j, i + warehouse->arr_trucks[i].size(), " ");
                        }
                    }
                }
        }

        for(int i = 0; i < port->cranes.size(); i++)
        {
            if(port->cranes[i]->isUsed)
            {
                if(craneAnim == '\\')
                {
                    mvprintw(port->cranes[i]->y, port->cranes[i]->x, "|");
                    craneAnim = '|';
                }
                else if(craneAnim == '|')
                {
                    mvprintw(port->cranes[i]->y, port->cranes[i]->x, "/");
                    craneAnim = '/';
                }
                else
                {
                    mvprintw(port->cranes[i]->y, port->cranes[i]->x, "\\");
                    craneAnim = '\\';
                }
            }
            else
            {
            mvprintw(port->cranes[i]->y, port->cranes[i]->x, "|");
            }
        }


        for(int j=0; j<=15; j++)//rysowanie magazynu
        {
            for(int i=0; i<12; i++)
            {
                if((j == 10 || j == 12) && i == 2)//przednia ściana
                {
                    mvprintw(j, i + ocean->length + warehouse->roadY+warehouse->roadLength, "]");
                }
                else if(j>7 && j<15 && i == 2)
                {
                    mvprintw(j, i + ocean->length + warehouse->roadY+warehouse->roadLength, "|");
                }

                if(j>7 && j<15 && i == 10)//tylna ściana
                {
                    mvprintw(j, i + ocean->length + warehouse->roadY+warehouse->roadLength, "|");
                }

                if((j == 7 || j == 15) && (i >= 2 && i <= 10))//górna ściana
                {
                    mvprintw(j, i + ocean->length + warehouse->roadY+warehouse->roadLength, "_");
                }

            }
        }

        refresh();

        std::this_thread::sleep_for(std::chrono::microseconds(500));
    }
}

Ui::~Ui()
{
    endwin();
}

