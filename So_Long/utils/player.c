#include "../so_long.h"

int exit_game(t_data *data, char *s)
{
    perror(s);
    mlx_destroy_window(data->mlx, data->win);
    exit(1);
    return (1);
}

int init_player(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->map_hei)
    {
        j = 0;
        while (j < data->map_wid)
        {
            if (data->map[i][j] == 'P')
            {
                data->player_x = j;
                data->player_y = i;
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

void move_player(int dierection, t_data *data)
{
    int old_x;
    int old_y;

    old_x = data->player_x;
    old_y = data->player_y;
    if (dierection == W)
        data->player_y--;
    else if (dierection == S)
        data->player_y++;
    else if (dierection == A)
        data->player_x--;
    else if (dierection == D)
        data->player_x++;
    if (data->player_x < 0 || data->player_x >= data->map_wid ||
        data->player_y < 0 || data->player_y >= data->map_hei ||
        data->map[data->player_y][data->player_x] == '1')
    {
        data->player_x = old_x;
        data->player_y = old_y;
    }
    else if (data->map[data->player_y][data->player_x] == 'C')
        data->collectible--;
    else if (data->map[data->player_y][data->player_x] == 'E' && data->collectible == 0)
        exit_game(data, "You Won");
        
}

int key_press(int key, t_data *data)
{
    if (key == W)
        move_player(W, data);
    else if (key == S)
        move_player(S, data);
    else if (key == A)
        move_player(A, data);
    else if (key == D)
        move_player(D, data);
    else if (key == ESC)
        exit_game(data, "Quit");
    return (0);
}
