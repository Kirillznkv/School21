#include "get_next_line.h"
#include "stdio.h"

int main(int argc, char **argv)
{
    char *line;
    while (get_next_line(0, &line))
        printf("|%s|\n", line);
    return 0;
}
