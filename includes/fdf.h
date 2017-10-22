/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:02:35 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/19 19:34:09 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct		s_coord
{
	int				y;
	int				x;
	int				z;
	struct t_coord	*right;
	struct t_coord	*down;
}					t_coord;

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
	unsigned int	zoom;
	t_list			*coords;
	int				ratio;
}					t_fdf;

int					read_file(char **av, t_fdf *fdf);
void				write_error(char *str);
void				build_connections(t_list *coords);
void				treatment(t_fdf *fdf);
int					key_parser(int keycode, t_fdf *fdf);

#endif
