/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_connections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:03:18 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/19 20:40:22 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	right_connections(int line, t_list *list)
{
	t_coord		*coord;

	coord = list->content;
	while (list && coord->x == line)
	{
		if (list->next)
			coord->right = list->next->content;
		list = list->next;
		if (list)
			coord = list->content;
	}
}

void	down_connections(t_list *before, t_list *after)
{
	t_coord		*coordbefore;
	t_coord		*coordafter;

	while (before && after)
	{
		coordbefore = before->content;
		coordafter = after->content;
		if (coordbefore->x == coordafter->x)
		{
			coordbefore->down = after->content;
			before = before->next;
			after = after->next;
		}
	}
}

void	build_connections(t_list *coords)
{
	int		current_line;
	t_list	*current;
	t_list	*before;
	t_coord	*tmpafter;
	t_coord	*tmpbefore;

	current_line = -1;
	current = coords;
	before = current;
	while (current)
	{
		tmpafter = current->content;
		tmpbefore = before->content;
		if (tmpbefore->y == tmpafter->y - 1)
		{
			down_connections(before, current);
			before = current;
		}
		if (current_line != tmpafter->y)
		{
			right_connections(tmpafter->y, current);
			current_line = tmpafter->y;
		}
		current = current->next;
	}
}
