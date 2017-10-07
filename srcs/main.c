/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:51:19 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/07 18:22:09 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	write_error(char *str)
{
	ft_dprintf(STDERR_FILENO, str);
	ft_dprintf(STDERR_FILENO, "\n");
	exit(-1);
}

int		main(int ac, char **av)
{
	t_fdf	fdf;

	fdf.mlx = mlx_init();
	if (read_file(ac, av, &fdf) == -1)
		write_error("Error during file reading");
	if (pthread_create(&fdf.tid, NULL, &treatment, &fdf) != 0)
		write_error("Error during thread creation");
	mlx_loop(fdf.mlx);
	return (0);
}
