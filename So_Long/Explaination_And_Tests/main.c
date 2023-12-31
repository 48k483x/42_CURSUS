#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/keysym.h>
#define MLX_ERROR 1
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 300
#define YELLOW 0xFFFF00
#define GREEN 0x008000
#define BLUE 0x1E90FF
#define WHITE 0xFFFFFF


typedef struct s_rect
{
    int x;
    int y;
    int wid;
    int hei;
    int color;
}   t_rect;

typedef struct s_img
{
    void *mlx_img;
    char *addr;
    int bpp;  /* bits per pixel  */
    int len_line;
    int endian;
}   t_img;


typedef struct s_data
{
    void *mlx;
    void *win;
    t_img img;
}   t_data;


int keypress_handle(int keypress, t_data *data)
{
    if (keypress == XK_Escape)
    {
        mlx_destroy_window(data->mlx, data->win);
        data->win = NULL;
    }
    return (0);
}

//void image_put(t_img )

int render_background(t_data *data, int color)
{
    int i;
    int j;

    if (data->win == NULL)
        return (1);
    i = 0;
    while (i < SCREEN_HEIGHT)
    {
        j = 0;
        while (j < SCREEN_WIDTH)
            mlx_pixel_put(data->mlx, data->win, j++,i,color);
        ++i;
    }
    return (0);
}

int render_rect(t_data *data, t_rect rect)
{
    int i;
    int j;
    
    if (data->win == NULL)
        return 1;
    i = rect.y;
    while (i < rect.y + rect.hei)
    {
        j = rect.x;
        while (j < rect.x + rect.wid)
            mlx_pixel_put(data->mlx, data->win, j++, i, rect.color);
        ++i;
    }
    return (0);
}
int render(t_data *data)
{
    if (data->mlx != NULL)
    {
        render_background(data, WHITE);
        render_rect(data, (t_rect){SCREEN_WIDTH - 100, SCREEN_HEIGHT - 100, 100, 100,BLUE});
        render_rect(data, (t_rect){0, 0, 100, 100,GREEN});
    }
    return (0);
}

int main() {
    t_data data;

    data.mlx = mlx_init();
    if (NULL == data.mlx)
	    return (MLX_ERROR);
    data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "My first thing ever");
    mlx_pixel_put(data.mlx, data.win, 100, 100,  YELLOW);
    if (NULL == data.win)
    {
    	free(data.win);
	    return (MLX_ERROR);
    }
    //data.img.mlx_img = mlx_new_image(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    mlx_loop_hook(data.mlx, &render, &data);
    mlx_hook(data.win, KeyPress, KeyPressMask, &keypress_handle, &data);
    mlx_loop(data.mlx);

    mlx_destroy_window(data.mlx, data.win);
    mlx_destroy_display(data.mlx);
    free(data.mlx);
}
