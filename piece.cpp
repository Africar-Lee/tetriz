#include "piece.h"
#include "game.h"

namespace gm
{
    Piece::Piece(Tetromino_axis &t, int x0, int y0, int i)
        : tetro_set(t),
          x(x0),
          y(y0),
          index(i),
          sp_playfield(std::make_shared<Matrix>(playfield)),
          status(1)
    {
        if (get_type() == 'I')
            offset = gm::offset_i;
        else if (get_type() == 'O')
            offset = gm::offset_o;
        else
            offset = gm::offset;
    }

    bool Piece::down()
    {
        return move(0, -1);
    }

    bool Piece::left()
    {
        return move(-1, 0);
    }

    bool Piece::right()
    {
        return move(1, 0);
    }

    bool Piece::rotate(int direct)
    {
        assert(direct >= 1 && direct <= 3);
        int new_index = (index + direct) % 4;
        for (auto i : iota(0, (int)offset[0].size()))
        {
            auto [dx_ori, dy_ori] = offset[index][i];
            auto [dx_new, dy_new] = offset[new_index][i];
            auto dx = dx_ori - dx_new;
            auto dy = dy_ori - dy_new;

            Piece new_piece(tetro_set, x, y, new_index);
            if (new_piece.test(x + dx, y + dy))
            {
                index = new_index;
                x += dx;
                y += dy;
                return true;
            }
        }

        return false;
    }

    bool Piece::test(int ox, int oy) const
    {
        assert(sp_playfield != nullptr);
        for (int i = 0; i < 4; ++i)
        {
            auto [dx, dy] = get_mino(i);
            // 1. 越界判断
            if ((ox + dx) < 0 || (ox + dx) > (*sp_playfield)[0].size() - 1 || (oy + dy) < 0 || (oy + dy) > (*sp_playfield).size() - 1)
            {
                return false;
            }
            // 有方块判断
            if ((*sp_playfield)[oy + dy][ox + dx] > 0)
            {
                return false;
            }
        }
        return true;
    }

    bool Piece::move(int dx, int dy)
    {
        if (!test(x + dx, y + dy))
            return false;
        x += dx;
        y += dy;
        return true;
    }

    char Piece::get_type() const
    {
        return tetro_set[index][0].first;
    }

    std::pair<int, int> Piece::get_mino(int i) const
    {
        assert(i >= 0 && i <= 3);
        if (i == 0)
            return {0, 0};
        return tetro_set[index][i];
    }

    std::pair<int, int> Piece::get_xy() const
    {
        return {x, y};
    }

    int Piece::get_color() const
    {
        if (status == 2)
            return (int)Color::White;
        return status ? tetro_set[index][0].second : 0 - tetro_set[index][0].second;
    }

    Tetromino_axis Piece::get_tetromino() const
    {
        return tetro_set;
    }

    void Piece::set_ghost()
    {
        status = 0;
    }

    void Piece::set_disable()
    {
        status = 2;
    }
} // namespace gm
