/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_connections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:03:18 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/24 16:08:17 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	build_connections(t_list *coords)
{
	t_list	*current;

	current = coords;
	while (current)
	{
		connections(current->content, coords);
		current = current->next;
	}
}
