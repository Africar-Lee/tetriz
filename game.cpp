#include "game.h"
#include "define.h"
#include "utils.h"
namespace gm{
    bool running;
    // int cursor_row, cursor_col;

    // Tetromino_matix cur_tetro;
    // Tetromino_set cur_tetro_set;
    // Tetromino_axis cur_tetro_pre;
    // int cur_index;

    Piece one_piece;
    Matrix playfield;
    Matrix render_frame;
    std::chrono::microseconds duration;

    void process()
    {
        render();
        if (ut::timer(duration))
        {
            one_piece.down();
        }
    }

    void render()
    {
        render_frame = playfield;
        auto [x, y] = one_piece.get_xy();

        // 正常块
        for (auto i : iota(0, 4)) // [0, 4)
        {
            auto [dx, dy] = one_piece.get_mino(i);
            render_frame[x + dx][y + dy] = one_piece.get_color();
        }

        // 投影块
        while (one_piece.test(x, --y))
            ;
        y++;
        for (auto i : iota(0, 4))
        {
            auto [dx, dy] = one_piece.get_mino(i);
            if (render_frame[x + dx][y + dy] == 0)
                render_frame[x + dx][y + dy] = 0 - one_piece.get_color();
        }
    }

    void quit()
    {
        running = false;
    }

    Piece pick()
    {
        // TODO: 拿取5格预览队列中的第一个元素
        return Piece(J_pre, 4, 20, 0);
    }
    void init()
    {
        running = true;
        one_piece = pick();
        playfield = Matrix(10, std::vector<int>(22, 0));
        duration = 500ms;
        render_frame = Matrix(10, std::vector<int>(22, 0));

        one_piece.set_playfield(std::make_shared<Matrix>(playfield));
    }

    void rotate()
    {
        one_piece.rotate();
    }

    void left()
    {
        one_piece.left();
    }

    void right()
    {
        one_piece.right();
    }

    void down()
    {
        one_piece.down();
    }
}