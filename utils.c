/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:44:39 by hfazaz            #+#    #+#             */
/*   Updated: 2024/05/29 20:56:03 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

long double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	pow = 1;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	if (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -1;
	}
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - '0');
	if (*s == '.')
		while (*++s)
			fractional_part += ((*s - '0') * (pow /= 10));
	return ((integer_part + fractional_part) * sign);
}
