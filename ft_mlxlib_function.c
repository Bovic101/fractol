/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlxlib_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:55:26 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/31 05:34:49 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

void	fractal_initialisation(t_ft_fractal *my_fractal)
{
	my_fractal->mlx_initialisation = mlx_init();
	if (my_fractal->mlx_initialisation == NULL)
	{
		handle_malloc_error(); // NT
	}
	my_fractal->mlx_win = mlx_new_window(my_fractal->mlx_initialisation, WIDTH,
			HEIGHT, my_fractal->fractal_set);
	if (my_fractal->mlx_win == NULL)
	{
		mlx_destroy_display(my_fractal->mlx_initialisation);
		free(my_fractal->mlx_initialisation);
		handle_malloc_error(); // NT
	}
	my_fractal->image.imageptr = mlx_new_image(my_fractal->mlx_initialisation,
			WIDTH, HEIGHT);
	if (my_fractal->image.imageptr == NULL)
	{
		mlx_destroy_window(my_fractal->mlx_initialisation, my_fractal->mlx_win);
		mlx_destroy_display(my_fractal->mlx_initialisation);
		free(my_fractal->mlx_initialisation);
		handle_malloc_error();
	}
	my_fractal->image.pptr = mlx_get_data_addr(my_fractal->image.pptr,
			&my_fractal->image.color_depth, &my_fractal->image.line_length,
			&my_fractal->image.endian);
}

void	handle_malloc_error(void)
{
	perror("Malloc error");
	exit(EXIT_FAILURE);
}
