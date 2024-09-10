#include "control.h"
#include "game.h"
#include "define.h"

namespace gm
{
    char command;

    std::map<char, std::function<void()>>
        comm_func{
            {KEY_Q, comm_quit},
            {KEY_W, comm_rotate},
            {KEY_A, comm_left},
            {KEY_D, comm_right},
            {KEY_S, comm_down},
            {KEY_SPAC, comm_drop},
        };

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

    void comm_rotate()
    {
        rotate();
        // cur_index = (cur_index + 1) % 4;
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
}
