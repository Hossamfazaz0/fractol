/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:44:20 by hfazaz            #+#    #+#             */
/*   Updated: 2024/05/30 01:50:52 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define GRAY 0x808080
# define LIGHT_GRAY 0xC0C0C0
# define DARK_GRAY 0x404040

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bbp;
	int		len;
	int		endian;

}			t_image;
typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	char	*name;
	t_image	img;
	int		iteration;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

void		fractol_init(t_fractal *fractal);
double		scale(double unscaled_num, double new_min, double new_max,
				double old_max);
t_complex	square_complex(t_complex z);
void		free_resources(t_fractal *fractal);
t_complex	sum_complex(t_complex z1, t_complex z2);
void		fractal_render(t_fractal *fractal);
void		handle_pixel(int x, int y, t_fractal *fractal);
int			keyboard_handle(int key_num, t_fractal *fractal);
void		data_init(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
long double	atodbl(char *s);
int			ft_strcmp(char *s1, char *s2);
#endif