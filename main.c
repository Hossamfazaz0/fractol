#include "fractol.h"
int main(int ac , char **av)
{
    t_fractal fractal;

    if(ac == 2 && !strncmp(av[1],"mandelbort",10)
    || ac == 4 && !strncmp(av[1],"julia",5))
    {
        fractal.name = av[1];
        fractol_init(&fractal);
        mlx_hook(fractal.mlx_window,2,0,close_window,&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else{
        printf("error");
    }
}