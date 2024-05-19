#include "fractol.h"
#include <ctype.h>
int valid(const char *str) {
    int has_dot = 0;
    int has_digit = 0;

    // Check for optional sign
    if (*str == '-' || *str == '+') {
        str++;
    }

    // Check each character
    while (*str) {
        if (*str == '.') {
            if (has_dot) {
                return 0; // More than one dot is invalid
            }
            has_dot = 1;
        } else if (isdigit(*str)) {
            has_digit = 1;
        } else {
            return 0; // Invalid character found
        }
        str++;
    }

    return has_digit;
}

int main(int ac, char **av) {
    t_fractal fractal;

    if ((ac == 2 && strcmp(av[1], "mandelbrot") == 0) ||
        (ac == 4 && strcmp(av[1], "julia") == 0)) {

        fractal.name = av[1];

        if (ac == 4 && strcmp(av[1], "julia") == 0) {
            if (!valid(av[2]) || !valid(av[3])) {
                printf("Error: Julia parameters must be valid floating-point numbers.\n");
                return 1;
            }

            fractal.julia_x = atof(av[2]);
            fractal.julia_y = atof(av[3]);
        }
        fractol_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    } else {
        printf("Usage: %s mandelbrot\n");
        printf("Usage: %s julia <julia_x> <julia_y>\n");
        return 1; 
    }
    return 0; 
}