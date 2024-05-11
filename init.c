#include "fractol.h"

static void malloc_error() {
    perror("error with allocation");
    malloc_error();
}

void fractol_init(t_fractal *fractal) {
    fractal->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL) {
        perror("Failed to initialize mlx");
        malloc_error();
    }

    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
    if (fractal->mlx_window == NULL) {
        perror("Failed to create window");
        mlx_destroy_display(fractal->mlx_connection);
        malloc_error();
    }

    fractal->img.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if (fractal->img.img == NULL) {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        malloc_error();
    }

    fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bbp, &fractal->img.len, &fractal->img.endian);
    if (fractal->img.addr == NULL) {
        perror("Failed to get image data address");
        mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        malloc_error();
    }
}
