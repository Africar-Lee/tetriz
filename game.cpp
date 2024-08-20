#include "game.h"
namespace gm{
    bool running;
    int cursor_row, cursor_col;

    void quit()
    {
        running = false;
    }

    void init()
    {
        running = true;
        cursor_row = 2;
        cursor_col = 15;
    }

    void rotate()
    {
        cursor_row--;
    }

    void left()
    {
        cursor_col--;
    }

    void right()
    {
        cursor_col++;
    }

    void down()
    {
        cursor_row++;
    }
}