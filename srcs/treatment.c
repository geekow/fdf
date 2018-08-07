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

void trace_line(t_xy *one, t_xy *two, t_fdf *fdf, int color)
{
	t_xy delta;
	t_xy inc;
	t_xy point;
	int i;
	int cumul;

	point.x = one->x;
	point.y = one->y;
	delta.x = two->x - one->x;
	delta.y = two->y - one->y;
	inc.x = ( delta.x > 0 ) ? 1 : -1 ;
	inc.y = ( delta.y > 0 ) ? 1 : -1 ;
	delta.x = abs(delta.x) ;
	delta.y = abs(delta.y) ;
	put_pixel(point.x, point.y, color, fdf) ;
	if ( delta.x > delta.y )
	{
		cumul = delta.x / 2 ;
		for ( i = 1 ; i <= delta.x ; i++ )
		{
			point.x += inc.x ;
			cumul += delta.y ;
			if ( cumul >= delta.x )
			{
				cumul -= delta.x ;
				point.y += inc.y;
			}
		put_pixel(point.x, point.y, color, fdf);
		}
	}
	else
	{
	  cumul = delta.y / 2 ;
	  for ( i = 1 ; i <= delta.y ; i++ )
	  {
		  point.y += inc.y;
		  cumul += delta.x ;
		  if (cumul >= delta.y)
		  {
			  cumul -= delta.y;
			  point.x += inc.x;
		  }
		put_pixel(point.x, point.y, color, fdf);
	}
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
