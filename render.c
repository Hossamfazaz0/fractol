#include "fractol.h"


void handle_pixel(int x,int y,t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    z.x = 0.0;
    z.y = 0.0;

    c.x = scale(x,-2,2,0,WIDTH);
    c.y = scale(x,2,-2,0,HEIGHT);

    while()
    {
        z = sum_complex(square_complex(z),c);
        if()
        {
            my_pixel_put();
            return;
        }
    }

}
void fractal_render(t_fractal *fractal)
{
    int c;
    int y;
    
    y = 0;
    while(y<HEIGHT)
    {
        x=0;
        while(x<WIDTH)
        {
            handle_pixel(x,y,fractal);
        }
    }
}