#pragma once
#include "define.h"
#include "tetromino.h"

namespace dw
{
    void window(int top, int left, int width, int height, std::string title);
    void tetromino(gm::Tetromino_matix &t, int top, int left);
    void tetromino(gm::Tetromino_set  &t, int top, int left, int index);
    void tetromino(gm::Tetromino_axis &t, int top, int left, int index);

    void frame(Matrix& frame, int top, int left);
}
