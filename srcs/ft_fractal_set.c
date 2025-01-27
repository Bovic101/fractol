/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 05:33:49 by vodebunm          #+#    #+#             */
/*   Updated: 2024/07/21 14:27:51 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

void	fractal_generator(t_ft_fractal *my_fractal)
{
	int	a;
	int	b;

	b = 0;
	ft_printf("Starting fractal generation\n");
	while (b < HEIGHT)
	{
		a = 0;
		while (a < WIDTH)
		{
			pixel_axes_handler(a, b, my_fractal);
			a++;
		}
		b++;
	}
	ft_printf("Finished fractal generation\n");
	mlx_put_image_to_window(my_fractal->mlx_initialisation, my_fractal->mlx_win,
		my_fractal->image.imageptr, 0, 0);
}

void	pixel_axes_handler(int a, int b, t_ft_fractal *my_fractal)
{
	t_complex_num	z;
	t_complex_num	c;
	int				i;
	int				colour;

	i = 0;
	if (!ft_strncmp(my_fractal->fractal_set, "Julia", 5))
	{
		z.a = (scale(a, (t_scale_range){0, WIDTH}, (t_scale_range){-2, 2})
				* my_fractal->zoom) + my_fractal->move_a;
		z.b = (scale(b, (t_scale_range){0, HEIGHT}, (t_scale_range){+2, -2})
				* my_fractal->zoom) + my_fractal->move_b;
		c.a = my_fractal->julia_param_a;
		c.b = my_fractal->julia_param_b;
	}
	else
	{
		z.a = 0.0;
		z.b = 0.0;
		c.a = (scale(a, (t_scale_range){0, WIDTH}, (t_scale_range){-2, 2})
				* my_fractal->zoom) + my_fractal->move_a;
		c.b = (scale(b, (t_scale_range){0, HEIGHT}, (t_scale_range){+2, -2})
				* my_fractal->zoom) + my_fractal->move_b;
	}
	while (i < my_fractal->iteration_point)
	{
		z = add_complex(multiply_complex(z), c);
		if ((z.a * z.a) + (z.b * z.b) > my_fractal->escape_radius)
		{
			colour = scale(i, (t_scale_range){0, my_fractal->iteration_point},
					(t_scale_range){BLACK, WHITE});
			new_mlx_pixel_put(&my_fractal->image, a, b, colour);
			return ;
		}
		i++;
	}
	new_mlx_pixel_put(&my_fractal->image, a, b, NAVY);
}

void	new_mlx_pixel_put(t_image *imgdata, int x, int y, int color)
{
	char	*img;

	img = imgdata->pptr + (y * imgdata->line_length + x * (imgdata->color_depth
				/ 8));
	*(unsigned int *)img = color;
}
