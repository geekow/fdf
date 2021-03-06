/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:51:19 by jjacobi           #+#    #+#             */
/*   Updated: 2018/10/09 20:56:03 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	write_error(char *str)
{
	ft_dprintf(STDERR_FILENO, str);
	ft_dprintf(STDERR_FILENO, "\n");
	exit(-1);
}

void	fdf_init(t_fdf *fdf)
{
	fdf->zoom = 25;
	fdf->x_offset = fdf->window_x / 4;
	fdf->y_offset = fdf->window_y / 2;
	fdf->y_factor = 3;
	fdf->x_factor = -1;
	fdf->z_factor = 1.4;
	fdf->z_zoom = 1;
}

int		refresh_img(t_fdf *fdf)
{
	treatment(fdf);
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf	fdf;

	ft_memset(&fdf, 0, sizeof(fdf));
	fdf.mlx = mlx_init();
	if (ac != 2 || read_file(av, &fdf) == -1)
		write_error("Error during file reading");
	build_connections(fdf.coords);
	fdf.window_x = 1000;
	fdf.window_y = 1000;
	fdf.windows = mlx_new_window(fdf.mlx, fdf.window_x, fdf.window_y, "42 FDF");
	fdf.image = mlx_new_image(fdf.mlx, fdf.window_x, fdf.window_y);
	fdf.imgdata = mlx_get_data_addr(fdf.image, &fdf.img_bits_per_pixel,
										&fdf.img_size_line, &fdf.img_endian);
	fdf.img_octet_per_pixel = fdf.img_bits_per_pixel / 8;
	fdf_init(&fdf);
	treatment(&fdf);
	mlx_expose_hook(fdf.windows, refresh_img, &fdf);
	mlx_hook(fdf.windows, 2, 1L << 0, key_parser, &fdf);
	KEYREPEAT;
	mlx_loop(fdf.mlx);
	return (0);
}
