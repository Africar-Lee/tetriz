#include "game.h"
#include "define.h"
#include "utils.h"
namespace gm
{
    bool running;
    bool locking;

    Piece one_piece;
    Matrix playfield;
    Matrix render_frame;

    std::queue<Tetromino_axis> next;

    std::chrono::microseconds duration;

    void init()
    {
        srand(std::time(0));

        running = true;
        locking = false;

        duration = 500ms;

        playfield = Matrix(PLY_FLD_ROWS, std::vector<int>(PLY_FLD_COLS, 0));
        preview();

        one_piece = pick();

        render_frame = Matrix(PLY_FLD_ROWS, std::vector<int>(PLY_FLD_COLS, 0));
    }

    void process()
    {
        render();
        if (ut::timer(duration))
        {
            // 如果无法继续下落，则锁定在游戏区
            if (one_piece.down())
                return;
            // 判断锁定标识是否可用
            if (locking)
            {
                // 锁定
                lock();
                // 消行
                clear();

                one_piece = pick(); // 前述锁定消行逻辑已完成，生成新piece

                locking = false;
            }
            else
            {
                locking = true;
            }
        }
    }

    void quit()
    {
        running = false;
    }

    void render()
    {
        render_frame = playfield;
        merge(render_frame, one_piece);

        // 投影块
        Piece ghost = one_piece;
        ghost.set_ghost();
        while (ghost.down())
            ;
        merge(render_frame, ghost);
    }

    Piece pick()
    {
        // TODO: 拿取5格预览队列中的第一个元素
        assert(!next.empty());
        Piece p(next.front(), 4, 20, 0);
        next.pop();
        preview();

        return std::move(p);
    }

    void lock()
    {
        merge(playfield, one_piece);
    }

    void clear()
    {
        for (auto it = playfield.begin(); it != playfield.end(); it++)
        {
            bool full = true;
            for (auto cell : (*it))
            {
                if (cell == 0)
                {
                    full = false;
                    break;
                }
            }
            if (full)
            {
                // 满行时进行消行操作
                it = playfield.erase(it);
                playfield.emplace_back(std::vector<int>(it->size(), 0));
                it--;
            }
        }
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

    void preview()
    {
        static std::vector<Tetromino_axis> bag = {I_pre, J_pre, L_pre, O_pre, S_pre, T_pre, Z_pre};
        int index{};
        while (next.size() < 5)
        {
            index = rand() % bag.size();
            next.push(bag[index]);
            bag.erase(bag.begin() + index);
            if (bag.empty())
                bag = {I_pre, J_pre, L_pre, O_pre, S_pre, T_pre, Z_pre};
        }
    }

    void drop()
    {
        while (one_piece.down())
            ;
        locking = true;
    }

    void merge(Matrix &m, const Piece &p)
    {
        auto [x, y] = p.get_xy();

        for (auto i : iota(0, 4)) // [0, 4)
        {
            auto [dx, dy] = p.get_mino(i);
            if (m[y + dy][x + dx] == 0)
                m[y + dy][x + dx] = p.get_color();
        }
    }
}