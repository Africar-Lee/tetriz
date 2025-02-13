#pragma once
#include "define.h"
#include "tetromino.h"

namespace dw
{
    void window(int top, int left, int width, int height, std::string title);
    void tetromino(Tetromino_axis &t, int top, int left, int index);

    void next(std::queue<Tetromino_axis> next5, int top, int left);

    void hold(Tetromino_axis hold_piece, int top, int left);

    void frame(Matrix &frame, int top, int left);

    void matrix(Matrix &m, int top, int left, Matrix *buffer = nullptr, std::string blank = "  ");
}
