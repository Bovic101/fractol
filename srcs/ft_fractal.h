/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:11:23 by vodebunm          #+#    #+#             */
/*   Updated: 2024/07/21 17:48:29 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTAL_H
# define FT_FRACTAL_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1200

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define GRAY 0x808080
# define SILVER 0xC0C0C0
# define MAROON 0x800000
# define OLIVE 0x808000
# define LIME 0x00FF00
# define PURPLE 0x800080
# define TEAL 0x008080
# define NAVY 0x000080
# define ORANGE 0xFFA500
# define PINK 0xFFC0CB
# define BROWN 0xA52A2A
# define GOLD 0xFFD700
# define LIGHT_GRAY 0xD3D3D3
# define DARK_GRAY 0xA9A9A9

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
	void	*mlx_initialisation;
	void	*mlx_win;
	char	*fractal_set;
	t_image	image;
	double	move_a;
	double	move_b;
	double	zoom;
	double	escape_radius;
	int		iteration_point;
	double	julia_param_a;
	double	julia_param_b;

}				t_ft_fractal;

double			scale(double x, t_scale_range x_range, t_scale_range y_range);
t_complex_num	add_complex(t_complex_num c, t_complex_num d);
t_complex_num	multiply_complex(t_complex_num c);
void			fractal_initialisation(t_ft_fractal *my_fractal);
void			handle_malloc_error(void);
void			pixel_axes_handler(int a, int b, t_ft_fractal *my_fractal);
void			populate_data(t_ft_fractal *my_fractal);
void			new_mlx_pixel_put(t_image *imgdata, int x, int y, int color);
void			fractal_generator(t_ft_fractal *my_fractal);
void			populate_event(t_ft_fractal *my_fractal);
int				keyboard_function(int keysym, t_ft_fractal *my_fractal);
int				mouse_function(int button, int x, int y,
					t_ft_fractal *my_fractal);
int				close_win_function(t_ft_fractal *my_fractal);
int				pointer_function(int a, int b, t_ft_fractal *my_fractal);

#endif