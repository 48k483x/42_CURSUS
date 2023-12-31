#include "so_long.h"

int main(int ac, char **av)
{

    if (ac != 2)
        return (0);
    int fd = open(av[1], O_RDONLY);
    char *line;
    char **map = NULL;
    while ((line = get_next_line(fd)))
    {
        map = add_to_map(map, line);
        //free(line);
    }
   for (int i = 0; map[i]; i++)
    {
        for (int j = 0; map[i][j]; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
    free(map);
    return (0);
}