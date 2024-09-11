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
        bool rotate(int direct);

        std::pair<int, int> get_mino(int i) const;

        std::pair<int, int> get_xy() const;

        int get_color() const;

        Tetromino_axis get_tetromino() const;

        void set_ghost();

        void set_disable();

        bool test(int x, int y) const;

    private:
        bool move(int dx, int dy);

        char get_type() const;

        Tetromino_axis tetro_set;
        int index; // [0, R, 2L, L]
        int x, y;
        int status; // 0:阴影状态，1:正常块，2:不可用
        std::shared_ptr<Matrix> sp_playfield;
        Offset offset; // 踢墙表
    };

} // namespace gm