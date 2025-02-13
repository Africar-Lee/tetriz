#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <functional>
#include <locale>
#include <memory>
#include <assert.h>
#include <ranges>
#include <fstream>
#include <cmath>

#ifdef __linux__
#include <termios.h>
#elif _WIN32
#include <conio.h>
#endif

#define KEY_Q       'q'
#define KEY_W       'w'
#define KEY_A       'a'
#define KEY_D       'd'
#define KEY_S       's'
#define KEY_SPAC    ' '
#define KEY_Z       'z'
#define KEY_X       'x'
#define KEY_C       'c'
#define KEY_R       'r'
#define KEY_H       'h'

#define TMN_STAT_NUM 4
#define BLKS_PER_TMN 4
#define PLY_FLD_ROWS 22
#define PLY_FLD_EX_ROWS 20
#define PLY_FLD_COLS 10

using namespace std::chrono_literals;
using Matrix = std::vector<std::vector<int>>;
using Tetromino_axis = std::vector<std::vector<std::pair<int, int>>>;
using Offset = std::vector<std::vector<std::pair<int, int>>>;
using std::ranges::views::iota;
