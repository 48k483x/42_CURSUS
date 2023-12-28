#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define MLX_ERROR 1
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 300

int main() {
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (NULL == mlx)
	    return (MLX_ERROR);
    win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "My first thing ever");
    if (NULL == win)
    {
    	free(win);
	return (MLX_ERROR);
    }
    while (1)
	    ;
    mlx_destroy_window(mlx ,win);
    mlx_destroy_display(mlx);
    free(mlx);
}
