#include "../so_long.h"

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

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
    new_map[i] = new_line;
    new_map[i + 1] = NULL;
    free(map);
    return (new_map);
}

int validate_map_walls(char **map)
{
    int i;
    int size;

    size = 0;
    while (map[size - 1])
        size++;
    i = 0;
    while(map[0][i] && map[size - 1][i])
     {
        if (map[0][i] != '1' || map[size - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while(i < size)
    {
        if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}


int validate_map(char **map, t_data *data)
{
    int i = 0;
    int j;
    int player = 0;
    int exit = 0;
    int collectible = 0;
    
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                player++;
            if (map[i][j] == 'E')
                exit++;
            if (map[i][j] == 'C')
                collectible++;
            j++;
        }
        i++;
    }
    if (player != 1 || exit != 1 || collectible < 1 || !validate_map_walls(map))
        return (0);
    data->collectible = collectible;
    return (1);
}