/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 15:51:19 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/23 22:30:38 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

void	modify_zoom(t_fdf *fdf, char increase)
{
	if (increase && fdf->zoom < UINT_MAX)
		fdf->zoom++;
	else if (!increase && fdf->zoom > 0)
		fdf->zoom--;
}

int		key_parser(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 69 || keycode == 78)
		modify_zoom(fdf, keycode == 69 ? 1 : 0);
	else if (keycode == 123)
		fdf->x_offset += 50;
	else if (keycode == 124)
		fdf->x_offset -= 50;
	else if (keycode == 126)
		fdf->y_offset += 50;
	else if (keycode == 125)
		fdf->y_offset -= 50;
	else if (keycode == 92)
		fdf->y_factor += 0.05;
	else if (keycode == 85)
		fdf->y_factor -= 0.05;
	else if (keycode == 91)
		fdf->x_factor += 0.05;
	else if (keycode == 84)
		fdf->x_factor -= 0.05;
	else if (keycode == 89)
		fdf->z_factor += 1;
	else if (keycode == 83)
		fdf->z_factor -= 1;
	else if (keycode == 86)
		fdf->z_factor = 1;
	else if (keycode == 87)
		fdf->x_factor = 0.5;
	else if (keycode == 88)
		fdf->y_factor = 0;
	else
		ft_printf("Unrecognized key pressed. Keycode: %i\n", keycode);
	treatment(fdf);
	return (0);
}
