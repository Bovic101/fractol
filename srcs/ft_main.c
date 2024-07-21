/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:13:45 by vodebunm          #+#    #+#             */
/*   Updated: 2024/07/21 15:08:41 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int	main(int argc, char **argv)
{
	t_ft_fractal	my_fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 10))
	{
		my_fractal.fractal_set = argv[1];
		fractal_initialisation(&my_fractal);
		fractal_generator(&my_fractal);
		mlx_loop(my_fractal.mlx_initialisation);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "Julia", 5))
	{
		my_fractal.fractal_set = argv[1];
		my_fractal.julia_param_a = ft_atoi_double(argv[2]);
		my_fractal.julia_param_b = ft_atoi_double(argv[3]);
		fractal_initialisation(&my_fractal);
		fractal_generator(&my_fractal);
		mlx_loop(my_fractal.mlx_initialisation);
	}
	else
	{
		ft_printf("Input incorrect: Enter correct Fractal Set name\n");
		exit(EXIT_FAILURE);
	}
}
