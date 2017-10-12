/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:32:04 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/12 16:06:59 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	reg_point(int x, int y, char *z, t_list *list)
{
	t_list	*result;
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	coord.z = ft_atoi(z);
	result = ft_lstnew(coord, sizeof(t_coord));
	if (list)
	{
		list->next = result;
	}
	else
	{
		;
	}
	return (0);
}

int	parse_line(char line, t_fdf *fdf, int x)
{
	char	**lineresult;
	int		y;
	t_list	*list;

	y = 0;
	list = fdf->coords;
	lineresult = ft_split_whitespaces(line);
	while (list && list->next)
		list = list->next;
	while (lineresult[y])
		if (reg_point(x, y, lineresult[y], list) != -1)
			return (-1);
	return (0);
}

int	read_file(char **av, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		x;

	x = 0;
	fd = open(av[1], O_RDONLY);
	fdf->coords = NULL;
	while (get_next_line(fd, &line))
		if (-1 == parse_line(line, fdf, x) && ++x)
			return (-1);
	return (0);
}
