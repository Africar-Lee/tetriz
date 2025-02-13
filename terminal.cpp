# include "terminal.h"
# include <iostream>

# define CSI "\033["

void tc::cursor_move_to(int row, int col)
{
    std::cout << CSI << row << ';' << col << 'H';
}

void tc::set_fore_color(int color_id)
{
    std::cout << CSI << "38;5;" << color_id << 'm';
}

void tc::set_back_color(int color_id)
{
    std::cout << CSI << "48;5;" << color_id << 'm';
}

void tc::clean_screen()
{
    std::cout << CSI << "2J";
}

void tc::reset_color()
{
    std::cout << CSI << "0m";
}

void tc::hide_cursor()
{
    std::cout << CSI << "?25l";
}

void tc::show_cursor()
{
    std::cout << CSI << "?25h";
}
