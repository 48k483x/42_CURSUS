#include "../so_long.h"

void restart_game(t_data *data)
{
    data->player_x = data->start_x;
    data->player_y = data->start_y;
    data->press = 0;
    data->key = S;
    data->reached = 1;

    collectibles_init(data, 0, 0);
    draw_background(data);
    draw_game(data);
}