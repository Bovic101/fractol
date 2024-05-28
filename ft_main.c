/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:13:45 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/28 14:37:23 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int	main(int argc, char **argv)
{
	t_ft_fractal	my_fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 10) || argc == 4
		&& !ft_strncmp(argv[1], "Julia", 5))
	{
		fractal_initialisation(&my_fractal);
		fractal_generation(&my_fractal);
		mlx_loop(my_fractal.mlx_initialisation);
	}
	else
	{
		printf("Input incorrect\n");
	}
}
