/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:07:17 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/19 20:43:18 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(int x, int y, char color, t_fdf *fdf)
{
	int	position;

	if (x < fdf->window_x && y < fdf->window_y)
	{
		position = (fdf->img_size_line * y + x) * fdf->img_bits_per_pixel;
		ft_memset(fdf->imgdata + position, color, fdf->img_bits_per_pixel);
	}
}

void	trace_point(t_fdf *fdf, t_coord *coord)
{
	put_pixel(coord->x, coord->y, 127, fdf);
}

void	treatment(t_fdf *fdf)
{
	t_list	*list;

	list = fdf->coords;
	while (list)
	{
		trace_point(fdf, list->content);
		list = list->next;
	}
}
