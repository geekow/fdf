/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:51:19 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/12 15:45:32 by jjacobi          ###   ########.fr       */
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
	if (ac != 2 || read_file(av, &fdf) == -1)
		write_error("Error during file reading");
	mlx_loop(fdf.mlx);
	return (0);
}
