
#include "../so_long.h"

int window_init(t_data *data)
{
    data->mlx = mlx_init();
    data->win = WIN(data->mlx, WINDOW_WID, WINDOW_HEI, "So Long");
    if (!data->mlx || !data->win)
        return (0);
    mlx_key_hook(data->win, key_press, data);
    mlx_loop(data->mlx);
    return (1);
}