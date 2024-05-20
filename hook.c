/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:44:26 by hfazaz            #+#    #+#             */
/*   Updated: 2024/05/20 18:52:50 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyboard_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(0);
	}
	else if (keysym == XK_Left)
		fractal->shift_x -= 0.5;
	else if (keysym == XK_Right)
		fractal->shift_x += 0.5;
	else if (keysym == XK_Up)
		fractal->shift_y += 0.5;
	else if (keysym == XK_Down)
		fractal->shift_y -= 0.5;
	fractal_render(fractal);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
		fractal->zoom *= 0.5;
	if (button == Button4)
		fractal->zoom /= 0.5;
	fractal_render(fractal);
}
