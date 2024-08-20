# include <iostream>
# include <thread>
# include <chrono>
# include "terminal.h"

using namespace std::chrono_literals;

int
main (void)
{
    // std::cout << "\033[5;10H"
    //           << "\033[38;5;214m"
    //           << "HelloWorld"
    //           << "\033[12;1H";

    // tc::cursor_move_to(5, 10);
    // tc::set_fore_color(214);
    // std::cout << "HelloWorld";
    // tc::cursor_move_to(10, 1);

    tc::hide_cursor();

    int i = 1;
    while (true) {
        std::this_thread::sleep_for(500ms);

        tc::clean_screen();

        tc::cursor_move_to(i++, 10);
        tc::set_back_color(15);
        std::cout << "  " << std::flush;
        tc::reset_color();
        tc::cursor_move_to(10, 1);
    }

    return 0;
}
