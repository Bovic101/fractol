/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:11:23 by vodebunm          #+#    #+#             */
/*   Updated: 2024/06/24 12:39:19 by vodebunm         ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 800

typedef struct specifix_complex_num
{
	double		a;
	double		b;
}				t_complex_num;

typedef struct scaling_value
{
	double		min;
	double		max;
}				t_scale_range;

// writing pixel to image

typedef struct image_data
{
	void		*imageptr;
	char		*pptr;
	int			color_depth;
	int			line_length;
	int			endian;
}				t_image;
// Mlx stuff

typedef struct fractal_window_struct
{
	void	*mlx_initialisation; // mlx_init
	void	*mlx_win;            // mlx_newwindow
	char	*fractal_set;
	// image manipulation
	t_image	image;
	//hook
	double	escape_radius;
	int		iteration_point;

}				t_ft_fractal;
double			scale(double x, t_scale_range x_range, t_scale_range y_range);
void			fractal_initialisation(t_ft_fractal *my_fractal);
void			handle_malloc_error(void);
void			pixel_axes_handler(int a, int b, t_ft_fractal *my_fractal);
t_complex_num	add_complex(t_complex_num c, t_complex_num d);
t_complex_num	multiply_complex(t_complex_num c);
void			populate_data(t_ft_fractal *my_fractal);

#endif