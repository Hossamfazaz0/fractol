#include "fractol.h"

int main(int ac, char **av)
{
    t_fractal fractal;

    if ((ac == 2 && strcmp(av[1], "mandelbrot") == 0) ||
        (ac == 4 && strcmp(av[1], "julia") == 0))
    {
        fractal.name = av[1];

        if (ac == 4 && strcmp(av[1], "julia") == 0)
        {
            fractal.julia_x = atodbl(av[2]);
            fractal.julia_y = atodbl(av[3]);
        }

        fractol_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        fprintf(stderr, "Usage: %s mandelbrot\n", av[0]);
        fprintf(stderr, "Usage: %s julia <julia_x> <julia_y>\n", av[0]);
        return 1; // Return non-zero to indicate an error
    }

    return 0; // Return zero to indicate successful execution
}
