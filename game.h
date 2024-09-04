#pragma once

#include "piece.h"

namespace gm{
    /*********************************
     * Variable in game
     *********************************/
    extern bool running;

    extern Piece one_piece; // 当前在下落的块

    // playfield[x][y], x = 0-9, y = 0-21
    extern Matrix playfield;    // 游戏场地
    extern std::chrono::microseconds duration;  // 时间间隔
    extern Matrix render_frame; //预渲染帧

    // extern int cursor_row, cursor_col;

    // extern Tetromino_matix cur_tetro;
    // extern Tetromino_set cur_tetro_set;
    // extern Tetromino_axis cur_tetro_pre;
    // extern int cur_index;

    /*********************************
     * Logic func in game
     *********************************/
    void process(); // 游戏运行主逻辑

    void quit();    // 游戏退出

    void init();    // 游戏初始化

    void render();  // 游戏每帧渲染

    Piece pick();   // 获取一个块

    void rotate();
    
    void left();
    
    void right();
    
    void down();
}