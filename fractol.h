#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "minilibx-linux/mlx.h"


#define WIDTH 800
#define HEIGHT 800
typedef struct s_complex{
    double x;
    double y;
}              t_complex;

typedef struct s_image
{
    void *img;
    void *addr;
    int bbp;
    int len;
    int endian;
    
}           t_image;
typedef struct s_fractal
{
    void *mlx_connection;
    void *mlx_window;
    char *name;
    t_image img;
}           t_fractal;

void fractol_init(t_fractal *fractal);
double scale(double unscaled_num,double new_min,double new_max,double old_min,double old_max);

#endif