#pragma once

#include "tetromino.h"
#include "define.h"

namespace gm
{
    class Piece
    {
    public:
        Piece(Tetromino_axis &t, int x0, int y0, int i);
        Piece() = default;

        bool down();
        bool left();
        bool right();
        bool rotate();


        std::pair<int, int> get_mino(int i) const;

        std::pair<int, int> get_xy() const;

        int get_color() const;

        void set_ghost();

        bool test(int x, int y) const;

    private:
        bool move(int dx, int dy);

        Tetromino_axis tetro_set;
        int index;  // [0, R, 2L, L]
        int x, y;
        int status; // 0:阴影状态，1:正常块
        std::shared_ptr<Matrix> sp_playfield;
    };
    // extern int cursor_row, cursor_col;

    // // extern Tetromino_matix cur_tetro;
    // // extern Tetromino_set cur_tetro_set;
    // extern Tetromino_axis cur_tetro_pre;
    // extern int cur_index;
}