#include "fractol.h"

static void my_pixel_put(int x, int y, t_image *img, int color)
{
    int offset;
    offset = (y * img->len) + (x * (img->bbp / 8));
    *(unsigned int *)(img->addr + offset) = color;
}
void mandel_julia(t_complex *z,t_complex *c,t_fractal *fractal)
{
    if(!strcmp(fractal->name,"julia"))
    {
        c->x = fractal->julia_x;
        c->y = fractal->julia_y;
    }
    else
    {
        c->x = z->x;
        c->y = z->y;
    }
}
void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i = 0;
    int color;


    z.x = (scale(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
    z.y = (scale(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;


    mandel_julia(&z,&c,fractal);

    while (i <fractal->iteration)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > 4)
        {
            color = scale(i, BLACK, WHITE, 0, fractal->iteration);
            my_pixel_put(x, y, &fractal->img, color);
            return;
        }
        i++;
    }
    my_pixel_put(x, y, &fractal->img, DARK_GRAY);

}

void fractal_render(t_fractal *fractal)
{
    int x;
    int y;
    y=0;
    while( y++ < HEIGHT)
    {
        x=0;
        while ( x++ < WIDTH)
            handle_pixel(x, y, fractal);
    }
    mlx_put_image_to_window(fractal->mlx_connection,
                            fractal->mlx_window,
                            fractal->img.img,
                            0, 0);
}
