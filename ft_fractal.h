/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:11:23 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/31 05:35:13 by vodebunm         ###   ########.fr       */
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

# define WIDTH	800
# define HEIGHT	800


// writing pixel to image

typedef struct image_data
{
	void	*imageptr;
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
	char	*fractal_set;
	// image manipulation
	t_image	image;
	// hook
}			t_ft_fractal;
void	fractal_initialisation(t_ft_fractal	*my_fractal);
void	handle_malloc_error(void);
#endif