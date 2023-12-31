#include "../so_long.h"

char **add_to_map(char **map, char *new_line)
{
    int i = 0;
    int size = 0;

    while (map && map[size])
        size++;
    char **new_map = malloc(sizeof(char *) * (size + 2));
    if (!new_map)
        return (NULL);
    while (i < size)
    {
        new_map[i] = map[i];
        i++;
    }
    new_map[size] = new_line;
    new_map[size + 1] = NULL;
    free(map);
    return (new_map);
}