#pragma once

#include "tetromino.h"

namespace gm{
    extern bool running;
    extern int cursor_row, cursor_col;

    extern Tetromino_matix cur_tetro;
    extern Tetromino_set cur_tetro_set;
    extern Tetromino_axis cur_tetro_pre;
    extern int cur_index;

    void quit();

    void init();

    void rotate();
    
    void left();
    
    void right();
    
    void down();
}