#include <iostream>
#include <thread>
#include <chrono>
#include <termios.h>
#include "terminal.h"
#include "utils.h"
#include "draw.h"

using namespace std::chrono_literals;

char command = 0;

char getch()
{
    char c{};
    struct termios old, cur;
    tcgetattr(0, &cur);
    old = cur;
    cfmakeraw(&cur);
    tcsetattr(0, 0, &cur);
    c = getchar();
    tcsetattr(0, 0, &old);

    return c;
}

void key_event()
{
    while (true)
    {
        command = getch();
        if (command == 'q')
            break;
    }
}

void init()
{
    tc::clean_screen();
    tc::hide_cursor();

    dw::window(1, 1, 9, 6, "Hold");
    dw::window(1, 10, 12, 22, "Tetriz");
    dw::window(7, 1, 9, 16, "Status");
    dw::window(19, 22, 8, 4, "Info");
    dw::window(1, 22, 8, 18, "Next");

    std::thread t(key_event);
    t.detach();
}

void loop()
{
    int i = 1;
    while (true)
    {

        tc::cursor_move_to(10, 4);
        std::cout << "FPS : " << ut::fps();

        tc::cursor_move_to(5, 10);
        tc::set_back_color(15);
        std::cout << "  " << std::flush;
        tc::reset_color();

        if (command == 'q') break;

        std::this_thread::sleep_for(100ms);
    }
}

void exit()
{
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
