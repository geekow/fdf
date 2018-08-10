/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:07:17 by jjacobi           #+#    #+#             */
/*   Updated: 2018/08/10 16:46:07 by jjacobi          ###   ########.fr       */
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
		return (cumul - ((cumul >= delta->x) ? delta->x : 0));
	}
	else
	{
		start_point->y += inc->y;
		cumul += delta->x;
		if (cumul >= delta->y)
			start_point->x += inc->x;
		return (cumul - ((cumul >= delta->y) ? delta->y : 0));
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
	while (i++ < ((delta.x > delta.y) ? delta.x : delta.y))
	{
		cumul = advance_segment(&start_point, &inc, &delta, cumul);
		put_pixel(start_point.x, start_point.y, color, fdf);
	}
}

void	apply_plan(t_xy *result, t_dcoord *coord, t_fdf *fdf)
{
	result->x = (coord->y * fdf->zoom) * sin(fdf->y_factor * M_PI);
	result->y = (coord->y * fdf->zoom) * cos(fdf->y_factor * M_PI);
	result->x += (coord->x * fdf->zoom) * sin(fdf->x_factor * M_PI);
	result->y += (coord->x * fdf->zoom) * cos(fdf->x_factor * M_PI);
	result->x += (coord->z * fdf->zoom) * sin(fdf->z_factor * M_PI);
	result->y += (coord->z * fdf->zoom) * cos(fdf->z_factor * M_PI);
	result->x += (fdf->x_offset * fdf->zoom);
	result->y += (fdf->y_offset * fdf->zoom);
}

//    T x[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

t_dcoord	*apply_cam(t_coord *coord)
{
	t_dcoord	*result;
	t_dcoord	cam[3];

	cam[0].x = 1;
	cam[0].y = 0;
	cam[0].z = 0;

	cam[1].x = 0;
	cam[1].y = 1;
	cam[1].z = 0;

	cam[2].x = 0;
	cam[2].y = 0;
	cam[2].z = 1;
	result = ft_memalloc(sizeof(t_coord));
	result->x = coord->x * cam[0].x + coord->y * cam[1].x + coord->z * cam[2].x + 0;
	result->y = coord->x * cam[0].y + coord->y * cam[1].y + coord->z * cam[2].y + 0;
	result->z = coord->x * cam[0].z + coord->y * cam[1].z + coord->z * cam[2].z + 0;
	return (result);
}

void	trace_point(t_fdf *fdf, t_coord *coord)
{
	t_xy	result;
	t_xy	tmp;

	apply_plan(&result, apply_cam(coord), fdf);
	put_pixel(result.x, result.y, 0x00AFFFFF, fdf);
	if (coord->right)
	{
		apply_plan(&tmp, apply_cam(coord->right), fdf);
		trace_line(&result, &tmp, fdf, 0x000000FF);
	}
	if (coord->down)
	{
		apply_plan(&tmp, apply_cam(coord->down), fdf);
		trace_line(&result, &tmp, fdf, 0x000000FF);
	}
}

void	print_axes(t_fdf *fdf)
{
	t_dcoord	center;
	t_dcoord	axe;
	t_xy	center_pos;
	t_xy	axe_pos;

	center.x = 0;
	center.y = 0;
	center.z = 0;
	apply_plan(&center_pos, &center, fdf);
	axe.x = 0;
	axe.y = 0;
	axe.z = 1;
	apply_plan(&axe_pos, &axe, fdf);
	trace_line(&center_pos, &axe_pos, fdf, 0x00FF0101);
	axe.x = 1;
	axe.z = 0;
	apply_plan(&axe_pos, &axe, fdf);
	trace_line(&center_pos, &axe_pos, fdf, 0x0001FF01);
	axe.x = 0;
	axe.y = 1;
	apply_plan(&axe_pos, &axe, fdf);
	trace_line(&center_pos, &axe_pos, fdf, 0x00FF01FF);
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
	if (fdf->show_axes)
		print_axes(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->windows, fdf->image, 0, 0);
	ft_memset(fdf->imgdata, 0, fdf->img_size_line * (fdf->window_y + 1));
}
