#include "define.h"
#include "terminal.h"
#include "utils.h"
#include "draw.h"
#include "control.h"
#include "game.h"
#include "tetromino.h"

void init()
{
    tc::hide_cursor();

    gm::init();
    gm::start_listener();

    setbuf(stdout, nullptr);

    tc::clean_screen();
    dw::window(1, 1, 9, 6, "Hold");
    dw::window(1, 10, 12, 22, "Tetriz");
    dw::window(7, 1, 9, 16, "Status");
    dw::window(19, 22, 8, 4, "Info");
    dw::window(1, 22, 8, 18, "Next");
}

void loop()
{
    int i = 1;
    while (gm::running)
    {
        gm::process();

        tc::cursor_move_to(10, 4);
        std::cout << "FPS : " << ut::fps();

        dw::frame(gm::render_frame, 2, 11);
        dw::next(gm::next, 2, 23);
        dw::hold(gm::hold_piece, 2, 2);

        tc::reset_color();

        std::cout << std::flush;
        std::this_thread::sleep_for(10ms);
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
