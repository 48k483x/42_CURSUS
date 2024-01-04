#include "../so_long.h"

char *filenames[PLAYER_FRAME];

void some_function(char **filenames) 
{
    filenames[0] = "assets/player/1.xpm";
    filenames[1] = "assets/player/2.xpm";
    filenames[2] = "assets/player/3.xpm";
    filenames[3] = "assets/player/4.xpm";
    filenames[4] = "assets/player/5.xpm";
    filenames[5] = "assets/player/6.xpm";
}

void collectible_function(char **filenames)
{
    filenames[0] = "assets/coll/1.xpm";
    filenames[1] = "assets/coll/2.xpm";
    filenames[2] = "assets/coll/3.xpm";
    filenames[3] = "assets/coll/4.xpm";
    filenames[4] = "assets/coll/5.xpm";
    filenames[5] = "assets/coll/6.xpm";
}

int standar_animation(t_data *data)
{
    static int counter = 0;

    if (counter == ANIMATION_SPEED)
    {
        data->current_frame = (data->current_frame + 1) % PLAYER_FRAME;
        draw_game(data);
        counter = 0;
    }
    else
    {
        counter++;
    }

    usleep(750); // delay for 100000 microseconds = 0.1 seconds

    return (0);
}