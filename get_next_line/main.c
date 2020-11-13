#include "get_next_line.h"
#include "stdio.h"

int main(int argc, char **argv)
{
    int res;
    char *line;
    while ((res = get_next_line(0, &line)) > 0)
    {
        printf("[Return: %d] Line #%s\n", res, line);
    }
    printf("[Return: %d] Line #%s\n", res, line);
    if (res == -1)
        printf("-----------\nError\n");
    else if (res == 0)
        printf("-----------\nEnd of file\n");
    return 0;
}
