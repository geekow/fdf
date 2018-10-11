/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:02:35 by jjacobi           #+#    #+#             */
/*   Updated: 2018/10/10 00:21:33 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include "ft_printf.h"

# ifdef __APPLE__
#  define KEYREPEAT mlx_do_key_autorepeaton(&fdf.mlx)
# else
#  define KEYREPEAT {}
# endif
# define HSV_DEGREE(X)	hsv_to_rgb(X, 1, 1) | 0x010101

typedef struct		s_coord
{
	int				y;
	int				x;
	int				z;
	int				fixed_color;
	int				color_degree;
	struct s_coord	*right;
	struct s_coord	*down;
}					t_coord;

typedef struct		s_dcoord
{
	double			y;
	double			x;
	double			z;
}					t_dcoord;

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef struct		s_fdf
{
	int				window_x;
	int				window_y;
	void			*mlx;
	void			*windows;
	void			*image;
	void			*imgdata;
	int				img_bits_per_pixel;
	int				img_octet_per_pixel;
	int				img_size_line;
	int				img_endian;
	int				x_offset;
	int				y_offset;
	char			show_axes;
	double			y_factor;
	double			x_factor;
	double			z_factor;
	double			z_zoom;
	double			zoom;
	t_list			*coords;
}					t_fdf;

int					read_file(char **av, t_fdf *fdf);
void				write_error(char *str);
void				build_connections(t_list *coords);
void				treatment(t_fdf *fdf);
int					key_parser(int keycode, t_fdf *fdf);
void				trace_line(t_xy *one, t_xy *two, t_fdf *fdf,
								int colors_deg[2]);
void				trace_line_fixed_color(t_xy *one, t_xy *two, t_fdf *fdf,
											int color);
int                 hsv_to_rgb(double h, double s, double v);

#endif
