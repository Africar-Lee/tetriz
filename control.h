#pragma once

namespace gm
{
    extern char command;
    char getch();

    void key_event();

    void start_listener();

    void comm_quit();
    void comm_rotate();
    void comm_left();
    void comm_right();
    void comm_down();
} // namespace gm
