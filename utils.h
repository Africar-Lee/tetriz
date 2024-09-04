#pragma once
#include "define.h"

namespace ut
{
    int fps();
    inline int b2c(int b)
    {
        return 2 * b - 1;
    }

    bool timer(std::chrono::microseconds msec);
} // namespace ut
