#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)))
		printf("%s", line);
	/*if (!line)
		printf("error in the line\n");*/
	/*printf("%s", line);*/
}
