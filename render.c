#include "fractol.h"

static void my_pixel_put(int x, int y, t_image *img, int color)
{
    int offset;
    // Calculate the offset within the image buffer
    offset = (y * img->len) + (x * (img->bbp / 8));
    // Assign the color value at the calculated offset
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

    c.x = scale(x, -2, 2, 0, WIDTH);
    c.y = scale(y, 2, -2, 0, HEIGHT);

    while (i < 2000)
    {
        // Iterate the fractal equation
        z = sum_complex(square_complex(z), c);
        // Check if the point is outside the fractal boundary
        if ((z.x * z.x) + (z.y * z.y) > 4)
        {
            // Color the pixel based on the iteration count
            color = scale(i, BLACK, WHITE, 0, 2000);
            my_pixel_put(x, y, &fractal->img, color);
            return;
        }
        i++;
    }
    // If the loop finishes without escaping, set the pixel color to CYAN
    my_pixel_put(x, y, &fractal->img, CYAN);
}

void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    // Iterate over all pixels in the image buffer
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            // Calculate and handle each pixel
            handle_pixel(x, y, fractal);
        }
    }
    // Display the rendered fractal in the window
    mlx_put_image_to_window(fractal->mlx_connection,
                            fractal->mlx_window,
                            fractal->img.img,
                            0, 0);
}
