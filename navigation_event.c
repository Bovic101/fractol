/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:09:53 by vodebunm          #+#    #+#             */
/*   Updated: 2024/07/21 05:09:23 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int	keyboard_function(int key, t_ft_fractal *my_fractal)
{
	if (key == 0xFF1B)
		close_win_function(my_fractal); // to
	if (key == 0xFF52)
		my_fractal->move_b -= 0.5;
	else if (key == 0xFF53)
		my_fractal->move_a -= 0.5;
	else if (key == 0xFF51)
		my_fractal->move_a += 0.5;
	else if (key == 0xFF54)
		my_fractal->move_b += 0.5;
	else if (key == 0x002B)
		my_fractal->iteration_point += 10;
	else if (key == 0x002D)
		my_fractal->iteration_point -= 10;
	fractal_generator(my_fractal);
	return (0);
}

int	mouse_function(int button, int x, int y, t_ft_fractal *my_fractal)
{
	if (button == Button5)
	{
		my_fractal->zoom *= 0.5;
	}
	else if (button == Button4)
	{
		my_fractal->zoom *= 1;
	}
}

int	close_win_function(t_ft_fractal *my_fractal)
{
	mlx_destroy_image(my_fractal->mlx_initialisation,
		my_fractal->image.imageptr);
	mlx_destroy_window(my_fractal->mlx_initialisation, my_fractal->mlx_win);
	mlx_destroy_display(my_fractal->mlx_initialisation);
	free(my_fractal->mlx_initialisation);
	exit(EXIT_SUCCESS);
}

int	pointer_function(int a, int b, t_ft_fractal *my_fractal)
{
}
