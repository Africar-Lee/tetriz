#pragma once

#include "define.h"
#include "color.h"

#define TMN_STAT_NUM 4
#define BLKS_PER_TMN 4

namespace gm
{
    using Tetromino_matix = std::vector<std::vector<int>>;
    // I[5][5] JLOSTZ[3][3]
    extern Tetromino_matix I, J, L, O, S, T, Z;

    Tetromino_matix rotate(Tetromino_matix &t);

    extern std::map<int, Color> tetro_color;

    //--------------------------------------------------
    using Tetromino_set = std::array<int, 4>;
    extern Tetromino_set I_set, J_set, L_set, O_set, S_set, T_set, Z_set;
    
    bool get_bit(int t, int i, int j);

    //--------------------------------------------------
    using Tetromino_axis = std::array<std::array<std::pair<int, int>, BLKS_PER_TMN>, TMN_STAT_NUM>;
    extern Tetromino_axis I_pre, J_pre, L_pre, O_pre, S_pre, T_pre, Z_pre;
}