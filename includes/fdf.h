/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:02:35 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/12 15:45:27 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "ft_printf.h"

typedef struct	s_coord
{
	int			y;
	int			x;
	int			z;
}				t_coord;

typedef struct	s_fdf
{
	void		*mlx;
	void		*windows;
	void		*image;
	t_list		*coords;
}				t_fdf;

int				read_file(char **av, t_fdf *fdf);
void			write_error(char *str);

#endif
