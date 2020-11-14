#include "get_next_line.h"
#include "stdio.h"

int main(int argc, char **argv)
{
    int 	res;
    char	*line;
	int		fd;

	fd = open("test", O_RDONLY);
    while ((res = get_next_line(180, &line)) > 0)
	{
        printf("|%s|\n", line);
		free(line);
	}
    printf("|%s|\n", line);
	free(line);
	close(fd);
   	fd = open("test_file17", O_RDONLY);
    while ((res = get_next_line(fd, &line)) > 0)
	{
        printf("|%s|\n", line);
		free(line);
	}
    printf("|%s|\n", line);
	free(line);
    return 0;
}
