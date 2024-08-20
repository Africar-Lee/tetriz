# include <iostream>
# include <unistd.h>

int
main (void)
{
    std::cout << "hello, world\n";

    int i = 0;
    while (i < 10) {
        i++;
    }

    return 0;
} 