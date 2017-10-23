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

void	apply_y(t_coord *coord, int y, t_fdf *fdf)
{
	coord->x = 50 + (y * fdf->zoom);
	coord->y = 100 - (fdf->zoom * y);
}

void	apply_x(t_coord *coord, int x, t_fdf *fdf)
{
	coord->x += 50 + (x * fdf->zoom);
	coord->y += 50 + (x * fdf->zoom);
}

void	apply_z(t_coord *coord, int z, t_fdf *fdf)
{
	coord->y -= z + fdf->zoom;
}

void	trace_point(t_fdf *fdf, t_coord *coord)
{
	t_coord	result;

	apply_y(&result, coord->y, fdf);
	apply_x(&result, coord->x, fdf);
	apply_z(&result, coord->z, fdf);
	put_pixel(result.x, result.y, 0xFFFFFF, fdf);
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
	mlx_put_image_to_window(fdf->mlx, fdf->windows, fdf->image, 0, 0);
	ft_memset(fdf->imgdata, 0, fdf->img_size_line * (fdf->window_y + 1));
}
