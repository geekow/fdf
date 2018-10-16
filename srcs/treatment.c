/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:07:17 by jjacobi           #+#    #+#             */
/*   Updated: 2018/10/10 00:16:44 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/*
** See https://en.wikipedia.org/wiki/Rotation_matrix#Basic_rotations
*/

void	apply_cam(t_xy *result, t_coord *coord, t_fdf *fdf)
{
	double		x;
	double		y;
	t_dcoord	tmp;

	tmp.z = coord->z * fdf->z_zoom;
	x = coord->x;
	tmp.x = cos(fdf->x_factor) * x + sin(fdf->x_factor) * tmp.z;
	tmp.z = -sin(fdf->x_factor) * x + cos(fdf->x_factor) * tmp.z;
	y = coord->y;
	tmp.y = cos(fdf->y_factor) * y - sin(fdf->y_factor) * tmp.z;
	tmp.z = sin(fdf->y_factor) * y + cos(fdf->y_factor) * tmp.z;
	x = tmp.x;
	y = tmp.y;
	tmp.x = cos(fdf->z_factor) * x - sin(fdf->z_factor) * y;
	tmp.y = sin(fdf->z_factor) * x + cos(fdf->z_factor) * y;
	tmp.x = (tmp.x * fdf->zoom) + fdf->x_offset;
	tmp.y = (tmp.y * fdf->zoom) + fdf->y_offset;
	result->x = (int)tmp.x;
	result->y = (int)tmp.y;
}

void	trace_point(t_fdf *fdf, t_coord *c)
{
	t_xy	tmp[2];
	int		colors_deg[2];

	apply_cam(&tmp[0], c, fdf);
	colors_deg[0] = c->color_degree;
	if (c->right)
	{
		colors_deg[1] = c->right->color_degree;
		apply_cam(&tmp[1], c->right, fdf);
		if (c->fixed_color || c->color_degree == c->right->color_degree)
			trace_line_fixed_color(&tmp[0], &tmp[1], fdf, (c->fixed_color ?
			c->fixed_color : HSV_DEGREE(c->color_degree)));
		else
			trace_line(&tmp[0], &tmp[1], fdf, colors_deg);
	}
	if (c->down)
	{
		colors_deg[1] = c->down->color_degree;
		apply_cam(&tmp[1], c->down, fdf);
		if (c->fixed_color || c->color_degree == c->down->color_degree)
			trace_line_fixed_color(&tmp[0], &tmp[1], fdf, (c->fixed_color ?
			c->fixed_color : HSV_DEGREE(c->color_degree)));
		else
			trace_line(&tmp[0], &tmp[1], fdf, colors_deg);
	}
}

void	print_axes(t_fdf *fdf)
{
	t_coord	center;
	t_coord	axe;
	t_xy	center_pos;
	t_xy	axe_pos;

	center.x = 0;
	center.y = 0;
	center.z = 0;
	apply_cam(&center_pos, &center, fdf);
	axe.x = 0;
	axe.y = 0;
	axe.z = 1;
	apply_cam(&axe_pos, &axe, fdf);
	trace_line_fixed_color(&center_pos, &axe_pos, fdf, 0xFF0101);
	axe.x = 1;
	axe.z = 0;
	apply_cam(&axe_pos, &axe, fdf);
	trace_line_fixed_color(&center_pos, &axe_pos, fdf, 0x01FF01);
	axe.x = 0;
	axe.y = 1;
	apply_cam(&axe_pos, &axe, fdf);
	trace_line_fixed_color(&center_pos, &axe_pos, fdf, 0xFF01FF);
}

void	treatment(t_fdf *fdf)
{
	t_list	*list;

	ft_memset(fdf->imgdata, 0, (size_t)fdf->img_size_line * fdf->window_y);
	list = fdf->coords;
	while (list)
	{
		trace_point(fdf, list->content);
		list = list->next;
	}
	if (fdf->show_axes)
		print_axes(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->windows, fdf->image, 0, 0);
}
