#include "fractol.h"
int main(int ac , char **av)
{
    t_fractal fractal;

    if(ac == 2 && !strcmp(av[1],"mandelbort")
    || ac == 4 && !strcmp(av[1],"julia"))
    {
        fractal.name = av[1];
        fractol_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else{
        printf("error");
    }
}