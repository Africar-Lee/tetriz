#include "window.h"
#include "draw.h"
#include "terminal.h"
#include "utils.h"
#include "game.h"

void ui::show_window()
{
    dw::window(1, 1, 9, 6, "Hold");
    dw::window(1, 10, 12, 22, "Tetriz");
    dw::window(7, 1, 9, 16, "Status");
    dw::window(19, 22, 8, 4, "Info");
    dw::window(1, 22, 8, 18, "Next");
}

void ui::show_status()
{
    tc::reset_color();
    tc::cursor_move_to(10, 4);
    std::cout << "FPS : " << ut::fps();
    tc::cursor_move_to(12, 4);
    std::cout << "Level : " << gm::level;
    tc::cursor_move_to(13, 4);
    std::cout << "Score : " << gm::score;
    tc::cursor_move_to(14, 4);
    std::cout << "Lines : " << gm::lines;

    if (gm::ending)
    {
        dw::window(9, 12, 8, 3, "");
        tc::cursor_move_to(10, ut::b2c(13));
        tc::set_fore_color((int)Color::Red);
        std::cout << " GAME OVER!";
    }

    if (gm::helping)
    {
        // dw::window(9, 9, 14, 7, "HELP INFO");
        tc::set_fore_color((int)Color::Yellow);

        tc::cursor_move_to(8, ut::b2c(12));
        std::cout << "Help info:        ";
        tc::cursor_move_to(9, ut::b2c(12));
        std::cout << "                  ";

        tc::cursor_move_to(10, ut::b2c(12));
        std::cout << "Rotate_Right:[w]";
        tc::cursor_move_to(11, ut::b2c(12));
        std::cout << "Move_Left:   [a]";
        tc::cursor_move_to(12, ut::b2c(12));
        std::cout << "Move_Right:  [d]";
        tc::cursor_move_to(13, ut::b2c(12));
        std::cout << "Move_Down:   [s]";
        tc::cursor_move_to(14, ut::b2c(12));
        std::cout << "Move_Drop:  [sp]";
        tc::cursor_move_to(15, ut::b2c(12));
        std::cout << "Hold_piece:  [c]";
        tc::cursor_move_to(16, ut::b2c(12));
        std::cout << "Reset_game:  [r]";
        tc::cursor_move_to(17, ut::b2c(12));
        std::cout << "Quit_game:   [q]";
    }
}

void ui::show_game()
{
    dw::frame(gm::render_frame, 2, 11);
    dw::next(gm::next, 2, 23);
    dw::hold(gm::hold_piece, 2, 2);
    tc::reset_color();

    std::cout << std::flush;
}

void ui::show_exit()
{
    tc::show_cursor();
    tc::reset_color();
    tc::clean_screen();
    tc::cursor_move_to(1, 1);
    tc::set_fore_color(9);
    std::cout << "Bye!" << std::endl;
    tc::reset_color();
}

void ui::show_help_info()
{
    tc::reset_color();
    tc::cursor_move_to(21, ut::b2c(24));
    std::cout << "Help [h]";
}
