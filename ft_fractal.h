/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:11:23 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/28 13:37:56 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTAL_H
# define FT_FRACTAL_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// writing pixel to image

typedef struct image_data
{
	void	*image;
	char	*pptr;
	int		color_depth;
	int		line_length;
	int		endian;
}			t_image;
// Mlx stuff

typedef struct fractal_window_struct
{
	void	*mlx_initialisation; // mlx_init
	void	*mlx_win; // mlx_newwindow
	// image manipulation
	t_image	image;
	// hooks
}			t_ft_fractal;

#endif