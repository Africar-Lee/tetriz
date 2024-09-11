#include "control.h"
#include "game.h"
#include "define.h"

namespace gm
{
    char command;

    std::map<char, std::function<void()>>
        comm_func{
            {KEY_Q, comm_quit},
            {KEY_W, comm_rotate_R},
            {KEY_Z, comm_rotate_L},
            {KEY_X, comm_rotate_2},
            {KEY_A, comm_left},
            {KEY_D, comm_right},
            {KEY_S, comm_down},
            {KEY_SPAC, comm_drop},
            {KEY_C, comm_hold},
            {KEY_R, comm_reset},
            {KEY_H, comm_help},
        };

#ifdef __linux__
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
#endif // __linux__

    void key_event()
    {
        while (running)
        {
            command = getch();
            if (comm_func.count(command) != 0)
                comm_func[command]();
        }
    }
    void start_listener()
    {
        std::thread t(gm::key_event);
        t.detach();
    }

    void comm_quit()
    {
        quit();
    }

    void comm_rotate_R()
    {
        rotate(1);
    }

    void comm_rotate_L()
    {
        rotate(3);
    }

    void comm_rotate_2()
    {
        rotate(2);
    }

    void comm_left()
    {
        left();
    }

    void comm_right()
    {
        right();
    }

    void comm_down()
    {
        down();
    }

    void comm_drop()
    {
        drop();
    }

    void comm_hold()
    {
        hold();
    }

    void comm_reset()
    {
        reset();
    }

    void comm_help()
    {
        help();
    }
}
