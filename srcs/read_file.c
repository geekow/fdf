/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:32:04 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/24 12:41:25 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int	reg_point(int x, int y, char *z, t_list **list)
{
	t_list	*result;
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	// while (z[i])
	// {
		// if (i == 0 && z[i] == '-')
			// i++;
		// else if (ft_isdigit(z[i]))
			// i++;
		// else
			// return (-1);
	// }
	coord.z = ft_atoi(z);
	coord.right = NULL;
	coord.down = NULL;
	if ((result = ft_lstnew(&coord, sizeof(t_coord))) == NULL)
		return (-1);
	*list = result;
	return (0);
}

int	parse_line(char *line, t_list **listadd, int x)
{
	char	**lineresult;
	int		y;
	t_list	*list;

	y = 0;
	lineresult = ft_split_whitespaces(line);
	list = NULL;
	while (lineresult[y])
	{
		if (reg_point(x, y, lineresult[y], &list) == -1)
			return (-1);
		list->next = *listadd;
		*listadd = list;
		list = NULL;
		y++;
	}
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
	{
		if (-1 == parse_line(line, &fdf->coords, x))
			return (-1);
		x++;
	}
	return (0);
}
