/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:13:45 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/27 21:28:13 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int	main(int argc, char **argv)
{
	t_ft_fractal	my_fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 10) || argc == 4
		&& !ft_strncmp(argv[1], "Julia", 5))
	{
		// todo
	}
	else
	{
		printf("Input incorrect\n");
	}
}
