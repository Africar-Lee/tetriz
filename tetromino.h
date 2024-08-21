#pragma once

#include "define.h"
#include "color.h"

namespace gm
{
    using Tetromino = std::vector<std::vector<int>>;
    // I[5][5] JLOSTZ[3][3]
    extern Tetromino I, J, L, O, S, T, Z;

    Tetromino rotate(Tetromino &t);

    extern std::map<int, Color> tetro_color;
}