/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:56:08 by hfazaz            #+#    #+#             */
/*   Updated: 2024/07/16 02:31:05 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	write(2, "error with allocation", 22);
	return ;
}

void	data_init(t_fractal *fractal)
{
	fractal->iteration = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	event_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, keyboard_handle,
		fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
}

void	fractol_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		free_resources(fractal);
		malloc_error();
	}
	fractal->img.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
	{
		free_resources(fractal);
		malloc_error();
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bbp,
			&fractal->img.len, &fractal->img.endian);
	if (fractal->img.addr == NULL)
	{
		free_resources(fractal);
		malloc_error();
	}
	data_init(fractal);
	event_init(fractal);
}

void	free_resources(t_fractal *fractal)
{
	if (fractal->img.img != NULL)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
	}
	if (fractal->mlx_window != NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	}
	if (fractal->mlx_connection != NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
}
