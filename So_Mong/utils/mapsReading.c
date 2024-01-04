#include "../so_long.h"

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int check_map_row_len(t_data *data)
{
    int i = 0;
    int len = ft_strlen(data->map[0]);

    while (data->map[i])
    {
        if (ft_strlen(data->map[i]) != len)
            return (0);
        i++;
    }
    return (1);
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

int validate_map_walls(char **map, t_data *data)
{
    int i;
    int size;

    size = 0;
    while (map[size])
        size++;
    i = 0;
    while(map[0][i] && map[size - 1][i])
     {
        if (map[0][i] != '1' || map[size - 1][i] != '1')
            return (0);
        i++;
    }
    data->map_wid = i;
    i = 0;
    while(i < size)
    {
        if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 1] != '1')
            return (1);
        i++;
    }
    data->map_hei = i;
    return (1);
}


int validate_map(t_data *data)
{
    int i = 0;
    int j;
    int player = 0;
    int exit = 0;
    data->collectible = 0;
    
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
                player++;
            else if (data->map[i][j] == 'E')
                exit++;
            else if (data->map[i][j] == 'C')
                data->collectible++;
            j++;
        }
        i++;
    }
    if (player != 1 || exit != 1 || data->collectible < 1 || !validate_map_walls(data->map, data))
        return (0);
    return (1);
}