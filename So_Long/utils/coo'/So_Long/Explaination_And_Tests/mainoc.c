#include "so_long.h"


int main()
{
    t_data *data;

    // Allocate memory for data
    data = malloc(sizeof(t_data));
    if (!data)
        return (1); // Return an error if malloc failed

    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WINDOW_WID, WINDOW_HEI, "So Long");

    if (!data->mlx || !data->win)
    {
        free(data); // Don't forget to free data if there's an error
        return (0);
    }

    //mlx_key_hook(data->win, key_press, data);
    mlx_loop(data->mlx);

    free(data); // Free data when you're done with it
    return (1);
}