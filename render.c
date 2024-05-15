#include "fractol.h"

static void my_pixel_put(int x, int y, t_image *img, int color)
{
    int offset;
    offset = (y * img->len) + (x * (img->bbp / 8));
    *(unsigned int *)(img->addr + offset) = color;
}

void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i = 0;
    int color;

    z.x = 0.0;
    z.y = 0.0;

    c.x = (scale(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
    c.y = (scale(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;

    while (i < fractal->iteration)
    {
        // Iterate the fractal equation
        z = sum_complex(square_complex(z), c);
        // Check if the point is outside the fractal boundary
        if ((z.x * z.x) + (z.y * z.y) > 4)
        {
            // Color the pixel based on the iteration count
            color = scale(i, BLACK, WHITE, 0, fractal->iteration);
            my_pixel_put(x, y, &fractal->img, color);
            return;
        }
        i++;
    }
    my_pixel_put(x, y, &fractal->img, LIGHT_GRAY);
    // fractal_render(fractal);
}

void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            
            handle_pixel(x, y, fractal);
        }
    }
    // Display the rendered fractal in the window
    mlx_put_image_to_window(fractal->mlx_connection,
                            fractal->mlx_window,
                            fractal->img.img,
                            0, 0);
}
