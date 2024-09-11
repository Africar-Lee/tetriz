#pragma once

#include "piece.h"

namespace gm
{
    /*********************************
     * Variable in game
     *********************************/
    extern bool running; // 游戏运行状态

    extern bool locking; // 锁定标识

    extern bool holding; // 暂存标识

    extern bool ending; // 终结标识

    extern Piece one_piece; // 当前在下落的块

    // playfield[x][y], x = 0-9, y = 0-21
    extern Matrix playfield;                   // 游戏场地
    extern std::chrono::microseconds duration; // 时间间隔
    extern Matrix render_frame;                // 预渲染帧

    extern std::queue<Tetromino_axis> next; // 预览队列

    extern Tetromino_axis hold_piece; // 暂存块

    extern int score; // 分数
    extern int level; // 等级
    extern int lines; // 消去的行数

    /*********************************
     * Logic func in game
     *********************************/
    void process(); // 游戏运行主逻辑

    void quit(); // 游戏退出

    void init(); // 游戏初始化

    void render(); // 游戏每帧渲染

    Piece pick(); // 获取一个块

    void lock(); // 锁定

    void clear(); // 消行

    void drop(); // 直落

    void rotate(int direct);

    void left();

    void right();

    void down();

    void preview(); // 生成预览队列

    void load(); // 载入预设地图

    void hold(); // 暂存游戏

    void levelup(); // 升级

    //---------- tool --------------
    void merge(Matrix &m, const Piece &p);
}