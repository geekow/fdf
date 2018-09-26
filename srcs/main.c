/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:51:19 by jjacobi           #+#    #+#             */
/*   Updated: 2018/08/10 16:26:38 by jjacobi          ###   ########.fr       */
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
	fdf->zoom = 1;
	fdf->x_offset = fdf->window_x / 12;
	fdf->y_offset = fdf->window_y / 5;
	fdf->y_factor = 0.65;
	fdf->x_factor = 0.25;
	fdf->z_factor = 1;
	fdf->cam[0].x = 1;
	fdf->cam[0].y = 0;
	fdf->cam[0].z = 0;
	fdf->cam[1].x = 0;
	fdf->cam[1].y = 1;
	fdf->cam[1].z = 0;
	fdf->cam[2].x = 0;
	fdf->cam[2].y = 0;
	fdf->cam[2].z = 1;
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
    mlx_hook(fdf.windows, 2, 1L<<0, key_parser, &fdf);
	KEYREPEAT
	mlx_loop(fdf.mlx);
	return (0);
}
