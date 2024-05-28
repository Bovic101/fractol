/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlxlib_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:55:26 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/28 14:55:26 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

void	fractal_initialisation(t_ft_fractal	*my_fractal)
{
	my_fractal->mlx_initialisation = mlx_init();
	if (my_fractal->mlx_initialisation == NULL)
	{
		handle_malloc_error();//To implement
	}
}
