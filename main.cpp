#include "define.h"
#include "terminal.h"
#include "utils.h"
#include "draw.h"
#include "control.h"
#include "game.h"
#include "tetromino.h"
#include "window.h"

void init()
{
#ifdef _WIN32
        system("chcp 65001");
#endif

    tc::hide_cursor();

    gm::init();
    gm::start_listener();

    tc::clean_screen();
    ui::show_window();
}

void loop()
{
    int i = 1;
    while (gm::running)
    {
        gm::process();
        ui::show_status();
        ui::show_game();
        ui::show_help_info();

        std::this_thread::sleep_for(10ms);
    }
}

void exit()
{
    gm::quit();
    ui::show_exit();
};

int main(void)
{
    tc::hide_cursor();

    init();
    loop();
    exit();

    return 0;
}
