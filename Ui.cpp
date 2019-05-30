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
                        mvprintw(j, i, "~");
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
            //if(port->cranes[i]->isUsed && port->cranes[i]->haveTruck)
            if(port->cranes[i]->status == CraneStatus::Working)
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

        //rysowanie statystyk morza
        mvprintw(1, 24 + ocean->length + warehouse->roadY+warehouse->roadLength, "Wind Direction:");
        switch (ocean->windDirection.load())
        {
        case 'S':
        mvprintw(2, 24 + ocean->length + warehouse->roadY+warehouse->roadLength, "S");
            break;
        case 'W':
            mvprintw(2, 24 + ocean->length + warehouse->roadY+warehouse->roadLength, "W");
            break;
        case 'E':
            mvprintw(2, 24 + ocean->length + warehouse->roadY+warehouse->roadLength, "E");
            break;
        default:
            mvprintw(2, 24 + ocean->length + warehouse->roadY+warehouse->roadLength, "N");
            break;
        }
        mvprintw(3, 24 + ocean->length + warehouse->roadY+warehouse->roadLength, "Storm:");//storm
        if(ocean->stormValue >= 5)
            mvprintw(4, 24 + ocean->length + warehouse->roadY+warehouse->roadLength, "ON");
        else
            mvprintw(4, 24 + ocean->length + warehouse->roadY+warehouse->roadLength, "OFF");

        mvprintw(5, 24 + ocean->length + warehouse->roadY+warehouse->roadLength, "Wave hight:");//fale
        if(ocean->waveHight >= 3)
            mvprintw(6, 24 + ocean->length + warehouse->roadY+warehouse->roadLength, "Low");
        else if(ocean->waveHight >= 7)
            mvprintw(6, 24 + ocean->length + warehouse->roadY+warehouse->roadLength, "Medium");
        else 
            mvprintw(6, 24 + ocean->length + warehouse->roadY+warehouse->roadLength, "High");

        refresh();

        std::this_thread::sleep_for(std::chrono::microseconds(500));
    }
}

Ui::~Ui()
{
    endwin();
}

