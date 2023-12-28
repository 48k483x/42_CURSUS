#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    void *mlx;
    mlx = mlx_init();
    mlx_destroy_display(mlx);
    free(mlx);
}
