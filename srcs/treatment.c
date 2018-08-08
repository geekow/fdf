/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:07:17 by jjacobi           #+#    #+#             */
/*   Updated: 2017/12/13 23:57:10 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	put_pixel(int x, int y, int color, t_fdf *fdf)
{
	int	position;

	if (x >= 0 && x < fdf->window_x && y >= 0 && y < fdf->window_y)
	{
		position = (fdf->img_size_line * y) + (x * fdf->img_octet_per_pixel);
		ft_strncpy(fdf->imgdata + position, (char*)&color,
													fdf->img_octet_per_pixel);
	}
}

int		advance_segment(t_xy *start_point, t_xy *inc, t_xy *delta, int cumul)
{
	if (delta->x > delta->y)
	{
		start_point->x += inc->x;
		cumul += delta->y;
		if (cumul >= delta->x)
			start_point->y += inc->y;
		return cumul - ((cumul >= delta->x) ? delta->x : 0);
	}
	else
	{
		start_point->y += inc->y;
		cumul += delta->x;
		if (cumul >= delta->y)
			start_point->x += inc->x;
		return cumul - ((cumul >= delta->y) ? delta->y : 0);
	}
}

/*
** The trace_line function is an implementation of Bresenham algorithm.
*/

void	trace_line(t_xy *one, t_xy *two, t_fdf *fdf, int color)
{
	t_xy	start_point;
	t_xy	delta;
	t_xy	inc;
	int		i;
	int		cumul;

	ft_memcpy(&start_point, one, sizeof(t_xy));
	delta.x = abs(two->x - one->x);
	delta.y = abs(two->y - one->y);
	inc.x = (two->x - one->x > 0) ? 1 : -1;
	inc.y = (two->y - one->y > 0) ? 1 : -1;
	put_pixel(start_point.x, start_point.y, color, fdf);
	i = 0;
	cumul = (delta.x > delta.y) ? delta.x / 2 : delta.y / 2;
	if (delta.x > delta.y)
		while (i++ < delta.x)
		{
			cumul = advance_segment(&start_point, &inc, &delta, cumul);
			put_pixel(start_point.x, start_point.y, color, fdf);
		}
	else
		while (i++ < delta.y)
		{
			cumul = advance_segment(&start_point, &inc, &delta, cumul);
			put_pixel(start_point.x, start_point.y, color, fdf);
		}
}

void	apply_plan(t_xy *result, t_coord *coord, t_fdf *fdf)
{
	// This function is probably not working as excepted
	result->x = coord->y * sin(fdf->y_factor * M_PI);
	result->y = coord->y * cos(fdf->y_factor * M_PI);
	result->x += coord->x * sin(fdf->x_factor * M_PI);
	result->y += coord->x * cos(fdf->x_factor * M_PI);
	result->x += coord->z * sin(fdf->z_factor * M_PI);
	result->y += coord->z * cos(fdf->z_factor * M_PI);
	result->x += fdf->x_offset;
	result->y += fdf->y_offset;
	result->x *= fdf->zoom;
	result->y *= fdf->zoom;
}

void	trace_point(t_fdf *fdf, t_coord *coord)
{
	t_xy	result;
	t_xy	tmp;

	apply_plan(&result, coord, fdf);
	put_pixel(result.x, result.y, 0xAFFFFF, fdf);
	if (coord->right)
	{
		apply_plan(&tmp, coord->right, fdf);
		trace_line(&result, &tmp, fdf, 0x0000FF);
	}
	if (coord->down)
	{
		apply_plan(&tmp, coord->down, fdf);
		trace_line(&result, &tmp, fdf, 0x0000FF);
	}
}

void	treatment(t_fdf *fdf)
{
	t_list	*list;
	t_xy	center;
	t_xy	z;
	t_xy	y;
	t_xy	x;

	center.x = 100;
	center.y = 100;
	
	z.x = 100;
	z.y = 50;

	y.x = 150;
	y.y = 100;

	x.x = 60;
	x.y = 125;
	
	// Lets print the plan axes
	trace_line(&center, &z, fdf, 0xFF0101);
	trace_line(&center, &y, fdf, 0x01FF01);
	trace_line(&center, &x, fdf, 0x0101FF);
	list = fdf->coords;
	while (list)
	{
		trace_point(fdf, list->content);
		list = list->next;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->windows, fdf->image, 0, 0);
	ft_memset(fdf->imgdata, 0, fdf->img_size_line * (fdf->window_y + 1));
}
