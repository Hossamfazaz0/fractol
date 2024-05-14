#include "fractol.h"

static void my_pixel_put(int x,int y , t_image *img,int color)
{
    
}

void handle_pixel(int x,int y,t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i = 0;
    int color;

    z.x = 0.0;
    z.y = 0.0;

    c.x = scale(x,-2,2,0,WIDTH);
    c.y = scale(x,2,-2,0,HEIGHT);

    while(i <42)
    {
        z = sum_complex(square_complex(z),c);
        if((z.x *z.x) + (z.y *z.y) > 4)
        {
            color = scale(i,BLACK,WHITE,0,42);
            my_pixel_put();
            return;
        }
    }

}
void fractal_render(t_fractal *fractal)
{
    int x;
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