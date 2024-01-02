
#include "../so_long.h"


int init_game(t_data *data)
{
    int wid;
    int hei;
    int i;
    char *filenames[PLAYER_FRAME];

    some_function(filenames);
    i = 0;
    while (i < PLAYER_FRAME)
    {
        data->player_img[i] = mlx_xpm_file_to_image(data->mlx, filenames[i], &wid, &hei);
        if (!data->player_img[i])
            exit_game(data, "Error loading images\n");
        i++;
    }
    data->background_img = mlx_xpm_file_to_image(data->mlx, "assets/backs/9amar.xpm", &wid, &hei);
    if (!data->background_img)
        exit_game(data, "Error loading images\n");
    data->empty_img = mlx_xpm_file_to_image(data->mlx, "assets/Objects/walks.xpm", &wid, &hei);
    data->wall_img = mlx_xpm_file_to_image(data->mlx, "assets/Objects/walls.xpm", &wid, &hei);
    data->collectible_img = mlx_xpm_file_to_image(data->mlx, "assets/coll/1.xpm", &wid, &hei);
    data->exit_img = mlx_xpm_file_to_image(data->mlx, "assets/Objects/exit1.xpm", &wid, &hei);
    if (!data->empty_img || !data->wall_img || !data->collectible_img || !data->exit_img)
        exit_game(data, "Error loading tile images\n");
    return (1);
}

/*void draw_game(t_data *data)
{
    data->player_x = WINDOW_WID / 2;
    data->player_y = WINDOW_HEI / 2;

    IMG(data->mlx, data->win, data->background_img, 0, 0);
    IMG(data->mlx, data->win, data->player_img[data->current_frame], data->player_x, data->player_y);
}*/


int draw_game(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < WINDOW_HEI)
    {
        j = 0;
        while (j < WINDOW_WID)
        {
            if (data->map[i][j] == 0)
                IMG(data->mlx, data->win, data->empty_img, j * TILE_WID, i * TILE_HEI);
            else if (data->map[i][j] == 1)
                IMG(data->mlx, data->win, data->wall_img, j * TILE_WID, i * TILE_HEI);
            else if (data->map[i][j] == 'E')
                IMG(data->mlx, data->win, data->exit_img, j * TILE_WID, i * TILE_HEI);
            else if (data->map[i][j] == 'C')
                IMG(data->mlx, data->win, data->collectible_img, j * TILE_WID, i * TILE_HEI);
            else if (data->map[i][j] == 'P')
                IMG(data->mlx, data->win, data->player_img[data->current_frame], j * TILE_WID, i * TILE_HEI);
            j++;
        }
        i++;
    }
    return (1);
}

int window_init(t_data *data)
{
    data->mlx = mlx_init();
    data->win = WIN(data->mlx, WINDOW_WID, WINDOW_HEI, "So Long");
    if (!data->mlx || !data->win)
        return (0);
    mlx_hook(data->win, 17, 0, exit_game, data);
    mlx_key_hook(data->win, key_press, data);
    init_game(data);
    draw_game(data);
    mlx_loop_hook(data->mlx, standar_animation, data);
    mlx_loop(data->mlx);
    return (1);
}