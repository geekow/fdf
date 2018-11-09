/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:32:04 by jjacobi           #+#    #+#             */
/*   Updated: 2018/10/09 23:24:57 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int	get_color(char *str)
{
	int len;
	int result;
	int i;
	int tmp;

	if (!str)
		return (0);
	i = 0;
	result = 0;
	str = &str[3];
	len = (int)ft_strlen(str);
	tmp = 0;
	while (str[i])
	{
		len--;
		if (str[i] >= '0' && str[i] <= '9')
			tmp = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			tmp = str[i] - 'a';
		else if (str[i] >= 'A' && str[i] <= 'F')
			tmp = str[i] - 'A';
		result += tmp * ft_power(16, len);
		i++;
	}
	return (result | 0x010101);
}

int	reg_point(int x, int y, char *z, t_list **list)
{
	t_list	*result;
	t_coord	coord;
	int		i;

	coord.x = x;
	coord.y = y;
	i = (z[0] && z[0] == '-') ? 1 : 0;
	while (z[i])
	{
		if (ft_isdigit(z[i]))
			i++;
		else if (ft_strstr(z, ",0x") && ft_strchr(",xABCDEFabcdef", z[i]))
			i++;
		else
			return (-1);
	}
	coord.z = ft_atoi(z);
	coord.fixed_color = get_color(ft_strstr(z, ",0x"));
	coord.color_degree = 0;
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
		free(lineresult[y]);
		y++;
	}
	free(lineresult);
	return (0);
}

int	read_file(char **av, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		x;

	x = 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	fdf->coords = NULL;
	while (get_next_line(fd, &line))
	{
		if (-1 == parse_line(line, &fdf->coords, x))
			return (-1);
		x++;
	}
	return (0);
}
