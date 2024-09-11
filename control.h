#pragma once

namespace gm
{
    extern char command;
#ifdef __linux__
    char getch();
#endif

    void key_event();

    void start_listener();

    void comm_quit();
    void comm_rotate_R();
    void comm_rotate_L();
    void comm_rotate_2();
    void comm_left();
    void comm_right();
    void comm_down();
    void comm_drop();
    void comm_hold();
    void comm_reset();
    void comm_help();
} // namespace gm
