#include "draw.h"
#include "terminal.h"
#include "define.h"
#include "utils.h"
#include "piece.h"
#include "tetromino.h"
#include "game.h"

/**
 *  	0	1	2	3	4	5	6	7	8	9	A	B	C	D	E	F
U+250x	─	━	│	┃	┄	┅	┆	┇	┈	┉	┊	┋	┌	┍	┎	┏
U+251x	┐	┑	┒	┓	└	┕	┖	┗	┘	┙	┚	┛	├	┝	┞	┟
U+252x	┠	┡	┢	┣	┤	┥	┦	┧	┨	┩	┪	┫	┬	┭	┮	┯
U+253x	┰	┱	┲	┳	┴	┵	┶	┷	┸	┹	┺	┻	┼	┽	┾	┿
U+254x	╀	╁	╂	╃	╄	╅	╆	╇	╈	╉	╊	╋	╌	╍	╎	╏
U+255x	═	║	╒	╓	╔	╕	╖	╗	╘	╙	╚	╛	╜	╝	╞	╟
U+256x	╠	╡	╢	╣	╤	╥	╦	╧	╨	╩	╪	╫	╬	╭	╮	╯
U+257x	╰	╱	╲	╳	╴	╵	╶	╷	╸	╹	╺	╻	╼	╽	╾	╿
 */
namespace dw
{
    void window(int top, int left, int width, int height, std::string title)
    {
        for (int r = 0; r < height; ++r)
        {
            tc::cursor_move_to(top + r, ut::b2c(left));
            for (int c = 0; c < width; ++c)
            {
                if (r == 0) // 第一行
                {
                    if (c == 0) // 第一列
                    {
                        std::cout << " ┌";
                    }
                    else if (c == width - 1) // 最后一列
                    {
                        std::cout << "┐ ";
                    }
                    else
                    {
                        std::cout << "──";
                    }
                }
                else if (r == height - 1) // 最后一行
                {
                    if (c == 0) // 第一列
                    {
                        std::cout << " └";
                    }
                    else if (c == width - 1) // 最后一列
                    {
                        std::cout << "┘ ";
                    }
                    else
                    {
                        std::cout << "──";
                    }
                }
                else
                {
                    if (c == 0) // 第一列
                    {
                        std::cout << " │";
                    }
                    else if (c == width - 1) // 最后一列
                    {
                        std::cout << "│ ";
                    }
                    else
                    {
                        std::cout << "  ";
                    }
                }
            }
        }
        // title
        tc::cursor_move_to(top, ut::b2c(left) + (width * 2 - title.length()) / 2);
        std::cout << title;
    }

    void tetromino(gm::Tetromino_matix &t, int top, int left)
    {
        for (int i = 0; i < t.size(); ++i)
        {
            tc::cursor_move_to(top + i, ut::b2c(left));
            for (int j = 0; j < t[0].size(); ++j)
            {
                if (t[i][j] > 0)
                {
                    tc::set_back_color((int)(gm::tetro_color[t[i][j]]));
                    std::cout << "  ";
                }
                else
                {
                    tc::reset_color();
                    std::cout << "  ";
                }
            }
        }
    }

    void tetromino(gm::Tetromino_set &t, int top, int left, int index)
    {
        for (int i = 0; i < 4; ++i)
        {
            tc::cursor_move_to(top + i, ut::b2c(left));
            for (int j = 0; j < 4; ++j)
            {
                if (gm::get_bit(t[index], i, j))
                {
                    tc::set_back_color((t[index] >> 16) & 0xff);
                    std::cout << "  ";
                }
                else
                {
                    tc::reset_color();
                    std::cout << "  ";
                }
            }
        }
    }

    void tetromino(gm::Tetromino_axis &t, int top, int left, int index)
    {
        tc::cursor_move_to(top, ut::b2c(left));
        tc::set_back_color(t[index][0].second);
        std::cout << "  ";
        for (auto p : t[index])
        {
            if (p.first > 'A')
                continue;
            // (dx, dy) -> (row, col)
            // row = row - dy
            // col = col + dx
            tc::cursor_move_to(top - p.second, ut::b2c(left + p.first));
            std::cout << "  ";
        }
    }

    void next(std::queue<gm::Tetromino_axis> next5, int top, int left)
    {
        static Matrix buffer(15, std::vector<int>(6, -1));
        Matrix next_field(15, std::vector<int>(6, 0));
        for (int y_pos = 13; !next5.empty(); y_pos -= 3)
        {
            gm::Piece p(next5.front(), 2, y_pos, 0);
            gm::merge(next_field, p);

            next5.pop();
        }

        matrix(next_field, top, left, &buffer);
    }

    void frame(Matrix &frame, int top, int left)
    {
        static Matrix buffer(frame.size(), std::vector<int>(frame[0].size(), -1));
        Matrix tmp_frame(frame.begin(), frame.begin() + 20);
        matrix(tmp_frame, top, left, &buffer, "\u30FB");
    }

    void matrix(Matrix &m, int top, int left, Matrix *buffer, std::string blank)
    {
        int row, col;
        for (int y = 0; y < m.size(); ++y)
        {
            for (int x = 0; x < m[0].size(); ++x)
            {
                if (buffer != nullptr)
                {
                    if ((*buffer)[y][x] == m[y][x])
                        continue;
                    (*buffer)[y][x] = m[y][x];
                }

                row = top + m.size() - y - 1;
                col = left + x;

                tc::cursor_move_to(row, ut::b2c(col));
                if (m[y][x] > 0) // 正常块
                {
                    tc::reset_color();
                    tc::set_back_color(m[y][x]);
                    std::cout << "  ";
                }
                else if (m[y][x] < 0) // 阴影块
                {
                    tc::reset_color();
                    tc::set_fore_color(0 - m[y][x]);
                    std::cout << "\u25E3\u25E5";
                }
                else // 空白区
                {
                    tc::reset_color();
                    std::cout << blank;
                }
            }
        }
    }
} // namespace dw
