/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:02:35 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/07 18:18:42 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "ft_printf.h"

typedef struct	s_fdf
{
	void		*mlx;
	void		*windows;
	void		*image;
}				t_fdf;

int				read_file(int ac, char **av, t_fdf *fdf);

#endif
