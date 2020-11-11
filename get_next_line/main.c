#include "get_next_line.h"
#include "stdio.h"

int main(int argc, char **argv)
{
    int res;
    char *line;
    while ((res = get_next_line(0, &line)))
    {
        printf("%d : |%s|\n", res, line);
        if (res < 0)
            return 0;
    }
    return 0;
}
