/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:07:17 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/24 15:24:36 by jjacobi          ###   ########.fr       */
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

void	apply_plan(t_xy *result, t_coord *coord, t_fdf *fdf)
{
	result->x = fdf->x_offset + coord->y * sin(fdf->y_factor * M_PI);
	result->y = fdf->y_offset + coord->y * cos(fdf->y_factor * M_PI);
	result->x += coord->x * sin(fdf->x_factor * M_PI);
	result->y += coord->x * cos(fdf->x_factor * M_PI);
	result->x += coord->z * sin(fdf->z_factor * M_PI);
	result->y += coord->z * cos(fdf->z_factor * M_PI);
	result->x *= fdf->zoom;
	result->y *= fdf->zoom;
}

// void	trace_line(t_xy *a, t_xy *b, t_fdf *fdf)
// {
// 	int	dx;
// 	int	dy;
// 	int	error;
//
// 	error = b->x - a->x;
// 	dx = error * 2;
// 	dy = (b->y - a->y) * 2;
// 	while (a->x <= b->x)
// 	{
// 		put_pixel(a->x, a->y, 0xFFFFFF, fdf);
// 		a->x += 1;
// 		if (error == error - dy)
// 		{
// 			a->y = a->y + 1;
// 			error += dx;
// 		}
// 	}
// }

void trace_line(t_xy *a, t_xy *b, t_fdf *fdf)
{
	if (a->x == b->x)
	{
		while (a->y++ < b->y)
			put_pixel(a->x, a->y - 1, 0xFFFFFF, fdf);
		while (b->y++ < a->y)
			put_pixel(b->x, b->y - 1, 0xFFFFFF, fdf);
	}
	else if (a->y == b->y)
	{
		while (a->x++ < b->x)
			put_pixel(a->x - 1, a->y, 0xFFFFFF, fdf);
		while (b->x++ < a->x)
			put_pixel(b->x - 1, b->y, 0xFFFFFF, fdf);
	}
	else if (a->x < b->x)
		while (a->x < b->x)
		{
			put_pixel(a->x, a->y, 0xFFFFFF, fdf);
			a->y += (b->y - a->y) / (b->x - a->x);
			a->x += 1;
		}
	else
		while (b->x < a->x)
		{
			put_pixel(b->x, b->y, 0xFFFFFF, fdf);
			b->y += (a->y - b->y) / (a->x - b->x);
			b->x += 1;
		}
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
		// put_pixel(tmp.x, tmp.y, 0x7F00FF, fdf);
		trace_line(&result, &tmp, fdf);
	}
	if (coord->down)
	{
		apply_plan(&tmp, coord->down, fdf);
		// put_pixel(tmp.x, tmp.y, 0x7F00FF, fdf);
		trace_line(&result, &tmp, fdf);
	}
}

void	treatment(t_fdf *fdf)
{
	t_list	*list;

	// t_xy	a;
	// t_xy	b;
	//
	// a.x = 0;
	// a.y = 100;
	// b.x = 100;
	// b.y = 0;
	// trace_line(&a, &b, fdf);

	list = fdf->coords;
	while (list)
	{
		trace_point(fdf, list->content);
		list = list->next;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->windows, fdf->image, 0, 0);
	ft_memset(fdf->imgdata, 0, fdf->img_size_line * (fdf->window_y + 1));
}
