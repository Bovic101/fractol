/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:18:32 by vodebunm          #+#    #+#             */
/*   Updated: 2024/06/16 11:45:52 by vodebunm         ###   ########.fr       */
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
	return (y_range.min + ((x - x_range.min) * (y_range.max - y_range.min)
			/ (x_range.max - x_range.min)));
}

/**int	main(void)
{
	t_scale_range	x;
	t_scale_range	y;

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
