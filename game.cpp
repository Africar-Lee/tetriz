#include "game.h"
namespace gm{
    bool running;
    int cursor_row, cursor_col;

    Tetromino cur_tetro;

    void quit()
    {
        running = false;
    }

    void init()
    {
        running = true;
        cursor_row = 2;
        cursor_col = 15;
        cur_tetro = S;
    }

    void rotate()
    {
        cur_tetro = rotate(cur_tetro);
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