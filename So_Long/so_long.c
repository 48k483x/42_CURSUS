#include "so_long.h"

int error_mssg(char *s, int ERR_TYPE)
{
    errno = ERR_TYPE; // Invalid argument
    perror(s);
    return (0);
}

int main(int ac, char **av)
{
    t_data data;
    if (ac != 2)
        return  (error_mssg("No Map Loaded, Try Again", EINVAL));
    int fd = open(av[1], O_RDONLY);
    char *line;
    char **map = NULL;
    while ((line = get_next_line(fd)))
        map = add_to_map(map, line);
    close(fd);
    if (!window_init(&data))
    {
        perror("Error: Failed to initialize window\n");
        return (1);
    }
    free(map);
    return (0);
}