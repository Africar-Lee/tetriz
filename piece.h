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

        void down();
        void left();
        void right();
        void rotate();

        void set_playfield(std::shared_ptr<Matrix> p);

        std::pair<int, int> get_mino(int i);

        std::pair<int, int> get_xy();

        int get_color();

        bool test(int x, int y);

    private:
        void move(int dx, int dy);

        Tetromino_axis tetro_set;
        int index; // [0, R, 2L, L]
        int x, y;
        std::shared_ptr<Matrix> sp_playfield;
    };
    // extern int cursor_row, cursor_col;

    // // extern Tetromino_matix cur_tetro;
    // // extern Tetromino_set cur_tetro_set;
    // extern Tetromino_axis cur_tetro_pre;
    // extern int cur_index;
}