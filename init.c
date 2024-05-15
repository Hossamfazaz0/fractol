#include "fractol.h"

static void malloc_error() {
    perror("error with allocation");
}

void fractol_init(t_fractal *fractal) {
    fractal->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL) {
        perror("Failed to initialize mlx");
        malloc_error();
        return; // Return if initialization fails to prevent further errors
    }

    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
    if (fractal->mlx_window == NULL) {
        perror("Failed to create window");
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
        return; // Return if window creation fails
    }

    fractal->img.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if (fractal->img.img == NULL) {
        perror("Failed to create image");
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
        return; // Return if image creation fails
    }

    fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bbp, &fractal->img.len, &fractal->img.endian);
    if (fractal->img.addr == NULL) {
        perror("Failed to get image data address");
        mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
        return; // Return if getting image data address fails
    }
}
