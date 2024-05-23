/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:44:39 by hfazaz            #+#    #+#             */
/*   Updated: 2024/05/23 18:19:19 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2, int n)
{
}

long double atodbl(char *s) {
	long integer_part = 0;
	double fractional_part = 0;
	double pow = 1;
	int sign = 1;

	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;

	if (*s == '+' || *s == '-') {
		if (*s++ == '-')
			sign = -1;
	}

	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - '0');

	if (*s == '.')
		while (*++s)
			fractional_part += (*s - '0') * (pow /= 10);

	return (integer_part + fractional_part) * sign;
}

