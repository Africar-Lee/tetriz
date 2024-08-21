#pragma once

#include "tetromino.h"

namespace gm{
    extern bool running;
    extern int cursor_row, cursor_col;

    extern Tetromino cur_tetro;

    void quit();

    void init();

    void rotate();
    
    void left();
    
    void right();
    
    void down();
}