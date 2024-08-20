#include "define.h"
#include "terminal.h"
#include "utils.h"
#include "draw.h"
#include "control.h"
#include "game.h"

void init()
{
    tc::clean_screen();
    tc::hide_cursor();

    dw::window(1, 1, 9, 6, "Hold");
    dw::window(1, 10, 12, 22, "Tetriz");
    dw::window(7, 1, 9, 16, "Status");
    dw::window(19, 22, 8, 4, "Info");
    dw::window(1, 22, 8, 18, "Next");

    gm::start_listener();
    gm::init();
}

void loop()
{
    int i = 1;
    while (gm::running)
    {

        tc::cursor_move_to(10, 4);
        std::cout << "FPS : " << ut::fps();

        tc::cursor_move_to(gm::cursor_row, ut::b2c(gm::cursor_col));
        tc::set_back_color(15);
        std::cout << "  " << std::flush;
        tc::reset_color();

        std::this_thread::sleep_for(100ms);
    }
}

void exit()
{
    gm::quit();
    tc::show_cursor();
    tc::reset_color();
    tc::clean_screen();
    tc::cursor_move_to(1, 1);
    tc::set_fore_color(9);
    std::cout << "Bye!" << std::endl;
};

int main(void)
{
    tc::hide_cursor();

    init();
    loop();
    exit();

    return 0;
}
