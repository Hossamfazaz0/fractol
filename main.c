/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:44:31 by hfazaz            #+#    #+#             */
/*   Updated: 2024/05/30 01:59:35 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	valid(const char *str)
{
	int	has_dot;
	int	has_digit;

	has_dot = 0;
	has_digit = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (ft_isdigit(*str))
			has_digit = 1;
		else
			return (0);
		str++;
	}
	return (has_digit);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0) || (ac == 4
			&& ft_strcmp(av[1], "julia") == 0))
	{
		fractal.name = av[1];
		if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
		{
			if (!valid(av[2]) || !valid(av[3]))
			{
				write(2, "Error: Julia parameters must be valid float.\n", 44);
				return (1);
			}
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		fractol_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		return (write(2, "Usage: mandelbrot\nUsage: julia <julia_x> \
<julia_y>\n", 51), 1);
	return (0);
}
