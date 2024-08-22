#include "tetromino.h"

namespace gm
{
    // IJLOSTZ
    // 1234567
    Tetromino_matix I{{
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    }};

    Tetromino_matix J{{{2, 0, 0},
                       {2, 2, 2},
                       {0, 0, 0}}};

    Tetromino_matix L{{{0, 0, 3},
                       {3, 3, 3},
                       {0, 0, 0}}};

    Tetromino_matix O{{{0, 4, 4},
                       {0, 4, 4},
                       {0, 0, 0}}};

    Tetromino_matix S{{{0, 5, 5},
                       {5, 5, 0},
                       {0, 0, 0}}};

    Tetromino_matix T{{{0, 6, 0},
                       {6, 6, 6},
                       {0, 0, 0}}};

    Tetromino_matix Z{{{7, 7, 0},
                       {0, 7, 7},
                       {0, 0, 0}}};

    std::map<int, Color> tetro_color{
        {1, Color::Cyan},
        {2, Color::Red},
        {3, Color::Orange},
        {4, Color::Yellow},
        {5, Color::Green},
        {6, Color::Blue},
        {7, Color::Purple},
    };

    Tetromino_matix rotate(Tetromino_matix &t)
    {
        Tetromino_matix result(t.size(), std::vector<int>(t.size(), 0));

        for (int i = 0; i < t.size(); ++i)
        {
            for (int j = 0; j < t[0].size(); ++j)
            {
                if (t[i][j] > 0)
                    result[j][t.size() - i - 1] = t[i][j]; // 实现旋转
            }
        }

        return std::move(result);
    }

    /*********************************************************
     * 尝试新的存储方案：使用位图存储
     *
     * i
     * 0000    0010    0000    0100
     * 1111    0010    0000    0100
     * 0000    0010    1111    0100
     * 0000    0010    0000    0100
     *
     * 0x0f00  0x2222  0x00f0  0x4444
     *
     * [0000 0000] << name:'I'
     * [0000 0000] << Color
     * [0000 0000] << data
     * [0000 0000] << data
     *
     * */
    Tetromino_set I_set = {
        0x0f00 | ((int)Color::Cyan << 16) | ('I' << 24),
        0x2222 | ((int)Color::Cyan << 16) | ('I' << 24),
        0x00f0 | ((int)Color::Cyan << 16) | ('I' << 24),
        0x4444 | ((int)Color::Cyan << 16) | ('I' << 24),
    };

    bool get_bit(int t, int i, int j)
    {
        return (t >> (i * 4 + j)) & 0x1 == 1;
    }

    /*********************************************************
     * 尝试新的存储方案：使用位图存储
     *
     * */
    Tetromino_axis I_pre = {{
        {{{'I', (int)Color::Cyan}, {-1, 0}, {1, 0}, {2, 0}}},
        {{{'I', (int)Color::Cyan}, {0, 1}, {0, -1}, {0, -2}}},
        {{{'I', (int)Color::Cyan}, {-2, 0}, {-1, 0}, {1, 0}}},
        {{{'I', (int)Color::Cyan}, {0, 2}, {0, 1}, {0, -1}}},
    }};
}