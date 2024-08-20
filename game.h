#pragma once

namespace gm{
    extern bool running;
    extern int cursor_row, cursor_col;

    void quit();

    void init();

    void rotate();
    
    void left();
    
    void right();
    
    void down();
}