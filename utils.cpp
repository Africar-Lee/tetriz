#include "utils.h"
#include "define.h"

using namespace std::chrono_literals;

int ut::fps()
{
    static auto start_time = std::chrono::steady_clock::now();
    auto end_time = start_time;
    static int frame_cnt = 0;
    static int fps = 0;

    frame_cnt++;
    end_time = std::chrono::steady_clock::now();
    if (end_time - start_time > 1s)
    {
        fps = frame_cnt;
        frame_cnt = 0;
        start_time = end_time;
    }

    return fps;
}

bool ut::timer(std::chrono::microseconds msec)
{
    static auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();

    if ((end - start) > msec)
    {
        start = end;
        return true;
    }
    return false;
}
