/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_connections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:03:18 by jjacobi           #+#    #+#             */
/*   Updated: 2018/10/09 18:43:03 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	connections(t_coord *coord, t_list *liststart)
{
	t_coord	*tmp;
	t_list	*list;

	list = liststart;
	coord->right = NULL;
	coord->down = NULL;
	while (list)
	{
		tmp = list->content;
		if (tmp->y == coord->y && tmp->x == coord->x + 1)
			coord->right = tmp;
		if (tmp->y == coord->y + 1 && tmp->x == coord->x)
			coord->down = tmp;
		if (coord->right && coord->down)
			return ;
		list = list->next;
	}
}

void	color_degree(t_list *liststart)
{
	t_list	*list;
	t_coord	*coord;
	int		min;
	int		max;
	float	tmp;

	list = liststart;
	min = INT32_MAX;
	max = INT32_MIN;
	while (list)
	{
		coord = list->content;
		if (coord->z < min)
			min = coord->z;
		if (coord->z > max)
			max = coord->z;
		list = list->next;
	}
	while (liststart)
	{
		coord = liststart->content;
		tmp = (float)(coord->z - min) / (float)(max - min);
		coord->color_degree = (int)(tmp * 310);
		liststart = liststart->next;
	}
}

void	build_connections(t_list *coords)
{
	t_list	*current;

	current = coords;
	while (current)
	{
		connections(current->content, coords);
		current = current->next;
	}
	color_degree(coords);
}
