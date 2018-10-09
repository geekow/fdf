/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 00:14:20 by jjacobi           #+#    #+#             */
/*   Updated: 2018/10/10 00:24:40 by jjacobi          ###   ########.fr       */
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

int		hsv_to_rgb(double h, double s, double v)
{
	double	p;
	double	q;
	double	t;

	if (s == 0)
		return ((int)(v * 255)) << 16 | ((int)(v * 255)) << 8 | (int)(v * 255);
	else
	{
		h = (h == 360) ? 0 : h / 60;
		p = v * (1.0 - s);
		q = v * (1.0 - (s * (h - (int)trunc(h))));
		t = v * (1.0 - (s * (1.0 - (h - (int)trunc(h)))));
		if ((int)trunc(h) == 0)
			return (int)(v * 255) << 16 | (int)(t * 255) << 8 | (int)(p * 255);
		else if ((int)trunc(h) == 1)
			return (int)(q * 255) << 16 | (int)(v * 255) << 8 | (int)(p * 255);
		else if ((int)trunc(h) == 2)
			return (int)(p * 255) << 16 | (int)(v * 255) << 8 | (int)(t * 255);
		else if ((int)trunc(h) == 3)
			return (int)(p * 255) << 16 | (int)(q * 255) << 8 | (int)(v * 255);
		else if ((int)trunc(h) == 4)
			return (int)(t * 255) << 16 | (int)(p * 255) << 8 | (int)(v * 255);
		else
			return (int)(v * 255) << 16 | (int)(p * 255) << 8 | (int)(q * 255);
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

void	trace_line(t_xy *one, t_xy *two, t_fdf *fdf, int colors_deg[2])
{
	t_xy	start_point;
	t_xy	delta;
	t_xy	inc;
	int		counters[4];
	double	percent;

	ft_memcpy(&start_point, one, sizeof(t_xy));
	delta.x = abs(two->x - one->x);
	delta.y = abs(two->y - one->y);
	inc.x = (two->x - one->x > 0) ? 1 : -1;
	inc.y = (two->y - one->y > 0) ? 1 : -1;
	counters[2] = hsv_to_rgb(colors_deg[0], 1, 1) | 0x010101;
	put_pixel(start_point.x, start_point.y, counters[2], fdf);
	counters[0] = 0;
	counters[1] = (delta.x > delta.y) ? delta.x / 2 : delta.y / 2;
	while (counters[0]++ < ((delta.x > delta.y) ? delta.x : delta.y))
	{
		counters[2] = colors_deg[1] - colors_deg[0];
		percent = counters[0] / (float)(delta.x > delta.y ? delta.x : delta.y);
		counters[2] = hsv_to_rgb(colors_deg[0] + (counters[2] * percent), 1, 1);
		counters[2] = counters[2] | 0x010101;
		counters[1] = advance_segment(&start_point, &inc, &delta, counters[1]);
		put_pixel(start_point.x, start_point.y, counters[2], fdf);
	}
}

void	trace_line_fixed_color(t_xy *one, t_xy *two, t_fdf *fdf, int color)
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
