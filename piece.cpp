#include "piece.h"

namespace gm
{
    Piece::Piece(Tetromino_axis &t, int x0, int y0, int i) : tetro_set(t), x(x0), y(y0), index(i)
    {
    }

    void Piece::down()
    {
        move(0, -1);
    }

    void Piece::left()
    {
        move(-1, 0);
    }

    void Piece::right()
    {
        move(1, 0);
    }

    void Piece::rotate()
    {
        index = (index + 1) % 4;
    }

    void Piece::set_playfield(std::shared_ptr<Matrix> p)
    {
        sp_playfield = p;
    }

    bool Piece::test(int ox, int oy)
    {
        assert(sp_playfield != nullptr);
        for (int i = 0; i < 4; ++i)
        {
            auto [dx, dy] = get_mino(i);
            // 1. 越界判断
            if ((ox + dx) < 0 || (ox + dx) > sp_playfield->size() - 1 || (oy + dy) < 0 || (oy + dy) > (*sp_playfield)[0].size() - 1)
            {
                return false;
            }
            // 有方块判断
            if ((*sp_playfield)[ox + dx][oy + dy] > 0)
            {
                return false;
            }
        }
        return true;
    }

    void Piece::move(int dx, int dy)
    {
        if (!test(x + dx, y + dy))
            return;
        x += dx;
        y += dy;
        return;
    }

    std::pair<int, int> Piece::get_mino(int i)
    {
        assert(i >= 0 && i <= 3);
        if (i == 0)
            return {0, 0};
        return tetro_set[index][i];
    }

    std::pair<int, int> Piece::get_xy()
    {
        return {x, y};
    }

    int Piece::get_color()
    {
        return tetro_set[index][0].second;
    }
} // namespace gm
