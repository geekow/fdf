/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 15:51:19 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/24 13:03:08 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>
#include "keycode.h"

void	modify_zoom(t_fdf *fdf, char increase)
{
	if (increase && fdf->zoom < UINT_MAX)
		fdf->zoom += 1;
	else if (!increase && fdf->zoom > 0)
		fdf->zoom -= 1;
}

void	modify_offset(int keycode, t_fdf *fdf)
{
	if (keycode == TOP)
		fdf->x_offset += (fdf->window_x / 16) / fdf->zoom;
	else if (keycode == BOTTOM)
		fdf->x_offset -= (fdf->window_x / 16) / fdf->zoom;
	else if (keycode == RIGHT)
		fdf->y_offset += (fdf->window_y / 16) / fdf->zoom;
	else if (keycode == LEFT)
		fdf->y_offset -= (fdf->window_y / 16) / fdf->zoom;
}

void	modify_axe(int keycode, t_fdf *fdf)
{
	if (keycode == NINE)
		fdf->y_factor += 0.01;
	else if (keycode == THREE)
		fdf->y_factor -= 0.01;
	else if (keycode == EIGHT)
		fdf->x_factor += 0.01;
	else if (keycode == TWO)
		fdf->x_factor -= 0.01;
	else if (keycode == SEVEN)
		fdf->z_factor += 0.01;
	else if (keycode == ONE)
		fdf->z_factor -= 0.01;
	else if (keycode == FOUR)
		fdf->z_factor = 1;
	else if (keycode == FIVE)
		fdf->x_factor = 0.25;
	else if (keycode == SIX)
		fdf->y_factor = 0.65;
}

int		key_parser(int keycode, t_fdf *fdf)
{
	if (keycode == ESCAPE)
		exit(0);
	else if (keycode == PLUS || keycode == MINUS)
		modify_zoom(fdf, keycode == PLUS ? 1 : 0);
	else if (ARROW_COND(keycode))
		modify_offset(keycode, fdf);
	else if (NBR_COND(keycode))
		modify_axe(keycode, fdf);
	else if (keycode == A)
		fdf->show_axes = (fdf->show_axes) ? 0 : 1;
	else if (keycode == E || keycode == R)
		fdf->cam[2].z += (keycode == E ? 0.01 : -0.01);
	else if (keycode == T || keycode == Y)
		fdf->cam[1].y += (keycode == T ? 0.01 : -0.01);
	else if (keycode == U || keycode == I)
		fdf->cam[0].x += (keycode == U ? 0.01 : -0.01);
	else
		ft_printf("Unrecognized key pressed. Keycode: %i\n", keycode);
	treatment(fdf);
	return (0);
}
