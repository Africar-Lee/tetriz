#include "tetromino.h"

namespace gm
{
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