#include "fractol.h"

int close_window(int key_num,t_fractal *fractal)
{
    if(key_num == 53)
        mlx_destroy_window(fractal->mlx_connection,fractal->mlx_window);
    return (0);