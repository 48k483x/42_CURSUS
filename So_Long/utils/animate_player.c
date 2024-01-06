#include "../so_long.h"

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
        data->current_frame = (data->current_frame + 1) % 10;
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
void righanime(t_data *data)
{
    static int i = 0;
    static int totalFrames = 20; // Adjust this for animation speed
    static float player_x_float = 0.0; // Player's x-coordinate as a floating-point number

    // Check if the player initiates movement to the right
    if (data->player_x < data->map_wid - 1 && data->map[data->player_y][data->player_x + 1] != '1')
    {
        // Initialize player_x_float to the current player position
        player_x_float = (float)data->player_x;
    }

    // Check if the animation should continue
    if (player_x_float < data->map_wid - 1 && data->map[data->player_y][(int)(player_x_float + 1)] != '1')
    {
        // Clear the previous frame
        draw_background(data);

        // Determine which sprite to draw based on the animation frame
        if (i < totalFrames / 2)
        {
            IMG(data->mlx, data->win, data->right, (int)(player_x_float * TILE_WID + 40), data->player_y * TILE_HEI + 40);
        }
        else
        {
            IMG(data->mlx, data->win, data->right1, (int)(player_x_float * TILE_WID + 40), data->player_y * TILE_HEI + 40);
        }

        i++;

        // Move the player a fraction of a tile each frame
        player_x_float += 1.0 / totalFrames;

        // Check if the animation is complete
        if (i >= totalFrames)
        {
            // Update the player's integer x-coordinate
            data->player_x = (int)player_x_float;

            // Reset the animation frame
            i = 0;

            // Clear the game
            draw_game(data);
        }
    }
}


