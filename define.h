#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <termios.h>
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

#define KEY_Q       'q'
#define KEY_W       'w'
#define KEY_A       'a'
#define KEY_D       'd'
#define KEY_S       's'
#define KEY_SPAC    ' '
#define KEY_Z       'z'
#define KEY_X       'x'

#define TMN_STAT_NUM 4
#define BLKS_PER_TMN 4
#define PLY_FLD_ROWS 22
#define PLY_FLD_EX_ROWS 20
#define PLY_FLD_COLS 10

using namespace std::chrono_literals;
using Matrix = std::vector<std::vector<int>>;
using Tetromino_axis = std::array<std::array<std::pair<int, int>, BLKS_PER_TMN>, TMN_STAT_NUM>;
using Offset = std::vector<std::vector<std::pair<int, int>>>;
using std::ranges::views::iota;
