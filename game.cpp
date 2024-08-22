#include "game.h"
namespace gm{
    bool running;
    int cursor_row, cursor_col;

    Tetromino_matix cur_tetro;
    Tetromino_set cur_tetro_set;
    Tetromino_axis cur_tetro_pre;
    int cur_index;

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
        cur_tetro_set = I_set;
        cur_tetro_pre = I_pre;
        cur_index = 0;
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