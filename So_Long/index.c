#include <unistd.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>


typedef struct s_data
{
    void *mlx;
    void *win;
}   t_data;

int
on_keypress(int keycode, t_data *data)
{
    (void)data;
    printf("keyPressedcode: %d\n", keycode);
    return (0);
}

int
destroy(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
    return (0);
}

int
main()
{
    t_data data;
    int width; int height;int i;
    void *frames[7];
    if (NULL == (data.mlx = mlx_init()))
        return (1);
    if (NULL == (data.win = mlx_new_window(data.mlx, 1720, 900, "Hi:)")))
        return ((free(data.mlx)), 1);
    // register a callback for key release event
    mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
    // register a callback for window close event
    mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &destroy, &data);
    // render image
    void *img = mlx_xpm_file_to_image(data.mlx, "/nfs/homes/achahrou/48k483x/48k483x_CUR5U5/So_Long/assets/shab.xpm", &width, &height);
    if (NULL == img)
        return ((free(data.mlx)), 1);
    mlx_put_image_to_window(data.mlx, data.win, img, 0, 0);
    // render the coin
    while (i < 7)
    {
        char filename[128];
        printf(filename, "frame%d.xpm", i);
        frames[i] = mlx_xpm_file_to_image(data.mlx, filename, &width, &height);
        if (frames[i] == NULL)
            return 1;

    }
    // keep the window open
    mlx_loop(data.mlx);
}