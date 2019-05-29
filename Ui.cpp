#include "Ui.hpp"


Ui::Ui(Ocean * o)
{
    ocean = o;

    initscr();
    noecho();
    raw();
    nodelay(stdscr, true);
    start_color();
    use_default_colors();
    curs_set(0);

}

void Ui::Update()
{
    while (true)
    {
        clrtoeol();
        for(int i = 0; i < ocean->arr_ships.size(); i++)
            for(int j = 0; j < ocean->arr_ships[i].size(); j++)
            {
                if(ocean->arr_ships[i][j] != 0)
                {
                    mvprintw(j, i, "#"); //"%d", ocean->arr_ships[i][j]);
                }
                else
                {
                    mvprintw(j, i, ".");
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

