/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:18:32 by vodebunm          #+#    #+#             */
/*   Updated: 2024/07/17 16:35:29 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

double	scale(double x, t_scale_range x_range, t_scale_range y_range)
{
	if (x_range.max == x_range.min)
	{
		perror("Error in min and max values");
		exit(EXIT_FAILURE);
	}
	return ((x - x_range.min) * (y_range.max - y_range.min) / (x_range.max
			- x_range.min) + y_range.min);
}

/**int	main(void)
{
	t_scale_range	x;
	t_scale_range	y;
	t_complex_num	result;

	x.min = 0.0;
	x.min = 299.0;
	y.min = -2.0;
	y.max = 2.0;
	for (size_t i = 0; i < 300; i++)
	{
		printf("%zu -> %f\n", i, scale((double)i, x, y));
	}
	return (0);
}**/
t_complex_num	add_complex(t_complex_num c, t_complex_num d)
{
	t_complex_num	result;

	result.a = c.a + d.a;
	result.b = c.b + d.b;
	return (result);
}

t_complex_num	multiply_complex(t_complex_num c)
{
	t_complex_num	result;

	result.a = c.a * c.a - c.b * c.b;
	result.b = 2 * c.a * c.b;
	return (result);
}
