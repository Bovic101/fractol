/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 05:33:49 by vodebunm          #+#    #+#             */
/*   Updated: 2024/06/24 12:38:52 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

void	fractal_generator(t_ft_fractal *my_fractal)
{
}

void	pixel_axes_handler(int a, int b, t_ft_fractal *my_fractal)
{
	t_complex_num	z;
	t_complex_num	c;
	t_scale_range	x_range;
	t_scale_range	y_range;
	int				i;

	i = 0;
	z.a = 0.0;
	z.b = 0.0;
	x_range.min = 0;
	x_range.max = WIDTH;
	y_range.min = 0;
	y_range.max = HEIGHT;
	c.a = (scale(a, (t_scale_range){-2, 2}, x_range));
	c.b = (scale(b, (t_scale_range){2, -2}, y_range));
	// time u want to iterate the mandelbrot func
	// z = z²+c
	while (i < my_fractal ->iteration_point)
	{
		z = add_complex(multiply_complex(z), c);
		if ((z.a * z.a) + (z.b * z.b) > my_fractal->escape_radius) //modulus
		{
			new_mlx_pixel_put/* code */
			return();//implement
		}
	}
	//Bounded in Mandelbrot
}
