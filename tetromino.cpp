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
        {{{'I', (int)Color::Cyan}, {-1, 0}, {1, 0}, {2, 0}}},       // 0
        {{{'I', (int)Color::Cyan}, {0, 1}, {0, -1}, {0, -2}}},      // R
        {{{'I', (int)Color::Cyan}, {-2, 0}, {-1, 0}, {1, 0}}},      // 2L
        {{{'I', (int)Color::Cyan}, {0, 2}, {0, 1}, {0, -1}}},       // L
    }};

    Tetromino_axis J_pre = {{
        {{{'J', (int)Color::Red}, {-1, 0}, {-1, 1}, {1, 0}}},       // 0
        {{{'J', (int)Color::Red}, {0, 1}, {0, -1}, {1, 1}}},        // R
        {{{'J', (int)Color::Red}, {1, -1}, {-1, 0}, {1, 0}}},       // 2L
        {{{'J', (int)Color::Red}, {0, 1}, {0, -1}, {-1, -1}}},      // L
    }};

    Tetromino_axis L_pre = {{
        {{{'L', (int)Color::Orange}, {-1, 0}, {1, 0}, {1, 1}}},     // 0
        {{{'L', (int)Color::Orange}, {0, 1}, {0, -1}, {1, -1}}},    // R
        {{{'L', (int)Color::Orange}, {-1, 0}, {1, 0}, {-1, -1}}},   // 2L
        {{{'L', (int)Color::Orange}, {0, 1}, {0, -1}, {-1, 1}}},    // L
    }};

    Tetromino_axis O_pre = {{
        {{{'O', (int)Color::Yellow}, {1, 0}, {0, 1}, {1, 1}}},      // 0
        {{{'O', (int)Color::Yellow}, {1, 0}, {0, -1}, {1, -1}}},    // R
        {{{'O', (int)Color::Yellow}, {-1, 0}, {0, -1}, {-1, -1}}},  // 2L
        {{{'O', (int)Color::Yellow}, {-1, 0}, {0, 1}, {-1, 1}}},    // L
    }};

    Tetromino_axis S_pre = {{
        {{{'S', (int)Color::Green}, {-1, 0}, {0, 1}, {1, 1}}},      // 0
        {{{'S', (int)Color::Green}, {0, 1}, {1, 0}, {1, -1}}},      // R
        {{{'S', (int)Color::Green}, {1, 0}, {0, -1}, {-1, -1}}},    // 2L
        {{{'S', (int)Color::Green}, {0, -1}, {-1, 0}, {-1, 1}}},    // L
    }};

    Tetromino_axis T_pre = {{
        {{{'T', (int)Color::Blue}, {-1, 0}, {1, 0}, {0, 1}}},       // 0
        {{{'T', (int)Color::Blue}, {0, 1}, {0, -1}, {1, 0}}},       // R
        {{{'T', (int)Color::Blue}, {1, 0}, {-1, 0}, {0, -1}}},      // 2L
        {{{'T', (int)Color::Blue}, {0, 1}, {0, -1}, {-1, 0}}},      // L
    }};

    Tetromino_axis Z_pre = {{
        {{{'Z', (int)Color::Purple}, {-1, 1}, {0, 1}, {1, 0}}},     // 0
        {{{'Z', (int)Color::Purple}, {1, 1}, {1, 0}, {0, -1}}},     // R
        {{{'Z', (int)Color::Purple}, {-1, 1}, {0, 1}, {1, 0}}},     // 2L
        {{{'Z', (int)Color::Purple}, {-1, -1}, {-1, 0}, {0, 1}}},   // L
    }};


/** 
 * J, L, S, T, Z Tetromino Offset Data
 *      Offset 1	Offset 2	Offset 3	Offset 4	Offset 5
 * 0	( 0, 0)	    ( 0, 0)	    ( 0, 0)	    ( 0, 0)	    ( 0, 0)
 * R	( 0, 0)	    (+1, 0)	    (+1,-1)	    ( 0,+2)	    (+1,+2)
 * 2	( 0, 0)	    ( 0, 0)	    ( 0, 0)	    ( 0, 0)	    ( 0, 0)
 * L	( 0, 0)	    (-1, 0)	    (-1,-1)	    ( 0,+2)	    (-1,+2)
 * 
 * 
 * I Tetromino Offset Data
 *      Offset 1	Offset 2	Offset 3	Offset 4	Offset 5
 * 0	( 0, 0)	    (-1, 0)	    (+2, 0)	    (-1, 0)	    (+2, 0)
 * R	(-1, 0)	    ( 0, 0)	    ( 0, 0)	    ( 0,+1)	    ( 0,-2)
 * 2	(-1,+1)	    (+1,+1)	    (-2,+1)	    (+1, 0)	    (-2, 0)
 * L	( 0,+1)	    ( 0,+1)	    ( 0,+1)	    ( 0,-1)	    ( 0,+2)
 * 
 * 
 * O Tetromino Offset Data
 *      Offset 1	Offset 2	Offset 3	Offset 4	Offset 5
 * 0	( 0, 0)	    No further offset data required
 * R	( 0,-1)
 * 2	(-1,-1)
 * L	(-1, 0)
 */
    Offset offset = {{
        {{{0, 0}, { 0, 0}, { 0, 0}, { 0, 0}, { 0, 0}}},  // 0
        {{{0, 0}, {+1, 0}, {+1,-1}, { 0,+2}, {+1,+2}}},  // R
        {{{0, 0}, { 0, 0}, { 0, 0}, { 0, 0}, { 0, 0}}},  // 2L
        {{{0, 0}, {-1, 0}, {-1,-1}, { 0,+2}, {-1,+2}}},  // L
    }};

    Offset offset_i = {{
        {{{ 0, 0}, {-1, 0}, {+2, 0}, {-1, 0}, {+2, 0}}},  // 0
        {{{-1, 0}, { 0, 0}, { 0, 0}, { 0,+1}, { 0,-2}}},  // R
        {{{-1,+1}, {+1,+1}, {-2,+1}, {+1, 0}, {-2, 0}}},  // 2L
        {{{ 0,+1}, { 0,+1}, { 0,+1}, { 0,-1}, { 0,+2}}},  // L
    }};

    Offset offset_o = {{
        {{{ 0, 0}}},  // 0
        {{{ 0,-1}}},  // R
        {{{-1,-1}}},  // 2L
        {{{-1, 0}}},  // L
    }};
}