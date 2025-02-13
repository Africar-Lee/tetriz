#include "game.h"
#include "define.h"
#include "utils.h"
namespace gm
{
    bool running;
    bool locking;
    bool holding;
    bool ending;
    bool resetting;
    bool helping;

    Piece one_piece;

    Matrix playfield;
    Matrix render_frame;

    std::queue<Tetromino_axis> next;

    Tetromino_axis hold_piece;

    std::chrono::microseconds duration;

    int score, level, lines;
    const int score_table[5] = {0, 100, 300, 500, 800};

    void init()
    {
        srand(std::time(0));

        running = true;
        locking = false;
        holding = false;
        ending = false;
        resetting = false;
        helping = false;

        score = 0;
        // level = 1;
        lines = 0;
        levelup();
        // duration = 500ms;

        playfield = Matrix(PLY_FLD_ROWS, std::vector<int>(PLY_FLD_COLS, 0));
        load();
        preview();

        one_piece = pick();

        render_frame = Matrix(PLY_FLD_ROWS, std::vector<int>(PLY_FLD_COLS, 0));
    }

    void process()
    {
        if (ending) return;

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
                // 消行并升级
                clear();
                levelup();

                one_piece = pick(); // 前述锁定消行逻辑已完成，生成新piece

                locking = false;
                holding = false;
                resetting = false;
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

        if (!p.test(4, 20))
        {
            // game over
            ending = true;
        }

        preview();

        return std::move(p);
    }

    void lock()
    {
        merge(playfield, one_piece);
    }

    void clear()
    {
        int cnt = 0;

        for (auto it = playfield.begin(); it != playfield.end();)
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
                playfield.push_back(std::vector<int>(it->size(), 0));
                cnt++;
                lines++;
            }
            else
            {
                ++it;
            }
        }

        score += score_table[cnt] * level;
    }

    void rotate(int direct)
    {
        one_piece.rotate(direct);
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
        if (one_piece.down())
            score += 1;
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

    void load()
    {
        std::ifstream fs("tetriz.map");
        if (!fs.is_open()) return;
        std::string line;

        for (auto &row : playfield | std::ranges::views::take(PLY_FLD_EX_ROWS) | std::ranges::views::reverse)
        {
            getline(fs, line);
            for (auto i : iota(0, PLY_FLD_COLS))
            {
                if (line[i] == '1')
                {
                    row[i] = (int)Color::Gray;
                }
            }
        }
        fs.close();
    }

    // 1. 如果暂存区为空，当前块放入暂存区，重新生成当前块，从头掉落
    // 2. 如果暂存区不空，当前块放入暂存区，使用原暂存区的块，从头掉落
    // 3. 每回合只允许使用暂存一次
    void hold()
    {
        if (holding)
            return;

        if (hold_piece.empty())
        {
            hold_piece = one_piece.get_tetromino();
            one_piece = pick();
        }
        else
        {
            auto tmp = hold_piece;
            hold_piece = one_piece.get_tetromino();
            one_piece = Piece(tmp, 4, 20, 0);
        }

        holding = true;
    }

    void levelup()
    {
        int tmp_time = 0;

        level = lines / 10 + 1;
        // duration = (0.8 - ((level - 1) * 0.007)) ^ (level - 1)
        tmp_time = (int)(pow((0.8 - ((level - 1) * 0.007)), (level - 1)) * 1000);
        duration = std::chrono::milliseconds(tmp_time);
    }

    void reset()
    {
        init();
        resetting = true;
    }

    void help()
    {
        helping = !helping;
        resetting = !helping;
    }

    void drop()
    {
        while (one_piece.down())
            score += 2;
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